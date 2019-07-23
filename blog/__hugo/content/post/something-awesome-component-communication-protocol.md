---
title: "Something Awesome: Component - Communication Protocol"
date: 2019-06-18T11:44:54+10:00

categories: ["Assessments", "Something Awesome"]
hiddenFromHomePage: false
postMetaInFooter: false

flowchartDiagrams:
  enable: false
  options: ""

sequenceDiagrams:
  enable: false
  options: ""

---

Writing my own application layer protocol was an... _interesting_ task.

> Gentle reminder to myself that TCP is stream based and that you need to split your payloads manually. [SO](https://stackoverflow.com/questions/24113273/when-sending-multiple-messages-to-a-node-js-tcp-socket-they-get-streamed-as-a-s)

Luckily I was able to reuse some [code from a previous project](https://github.com/featherbear/PreSonus-StudioLive-API/blob/master/PreSonusAPI.js#L61-L102) - which saved me some time

---

# Dealing with TCP packets

Because TCP is stream-based, I need to devise my own way of splitting my application packets.  

Most application TCP implementations that I've researched say to implement one of the two methods ([example](https://medium.com/@nikolaystoykov/build-custom-protocol-on-top-of-tcp-with-node-js-part-1-fda507d5a262)):

## 1) Prefix the length of the packet  

If we add the length of the payload to the start of the packet, we could read the length to know how many further bytes to read.

An issue with this is the number of bytes that will be used.  
If we use 2 bytes, we are limited to a maximum payload of 65536 (2^16) bytes - that's about 64KB of data.  
But what if you were going to transmit more than 64KB?

## 2) Use a delimiter to separate packets

But, if the payload contains the delimiter sequence then we'll run into splitting errors. One way to overcome this is to ensure that the payload won't contain the delimeter characters (for example encode the message (in base64?))

## 3) Or a mixture of both

---

# Thoughts

Ideally I'd want to use `0x00` as some sort of delimeter - but the `0x00` byte _may_ appear in the payload.  
Perhaps if I could just strip the `0x00` bytes - but there _might_ be a need to keep it within the data (?).  

If I encode the data with Base64 for example, the `0x00` byte will never occur - But base64 encoding might make the payload massive; so that's a turndown.  
Maybe I could escape the `0x00` characters.

With prefixing the length of a packet, I may run into overflow errors.  
If I maliciously craft a packet to have 9999999 bytes, the program will try read the next 9999999 bytes that are 'supposedly' part of a packet. 
This could cause a denial of service and would require a restart of the server.

Ultimately I will need to encrypt my payloads too.  
Perhaps the encryption doesn't produce any output bytes of `0x00` - but I shouldn't intertwine the need for encryption for both security and transport.

## Decision 

I probably won't use a delimeter, because I'm not sure how to effectively ignore possible delimeter sequences within the payload.  

The length will be stored in Little Endian formatting.  

By default, the length bytes will be 24 bits (3 bytes) long.  
If the length payload is `0x00 0x00 0x00`, then the next four bytes will determine the length (as a 32 bit number).

Therefore, for payloads under 16 MB, the length bytes will be 3 bytes long.  
For payloads between 16 MB and 4096 MB (4 GB), the length bytes will be 4 bytes long.

Any payload above 4096 MB will be rejected.

**For payloads up to 16777216 (2^(3*8)) bytes**  

```
|   3 bytes   | n bytes |
|   length n  | payload |
```

**For payloads greater than 16777216 bytes**  
```
|      3 bytes     |  4 bytes   |  n bytes  |
|  0x00 0x00 0x00  |  length n  |  payload  |
```

Will use the [`int24`](https://github.com/matanamir/int24) node module.

----

| Technical |


The Socket for each connection on the server will receive events - rather than the Server receiving events.  
This is as to allow each event to have a connection context (otherwise we will have to pass in the context via the argument)

---


---

# Other Musings

## ACK packets

Should I have some sort of acknowledgement packet that gets sent back to confirm reception?

## EventEmitters

Also I didn't realise that `EventEmitters` exist in node.js with `require('events').EventEmitter`.  
_I thought that every developer had written their own in the same way..._ - silly me.

## net.Socket

Node.js's `Socket.write` also has a ``Socket._write` method [source](https://github.com/nodejs/node/blob/ad2036fc1a7114bdb961d176fcabca4e0a7b92f5/lib/net.js#L302).  
This caused issues when I was trying to write a wrapper function to hook onto the `write` calls.  
I didn't receive any errors or warnings, so it was very hard to debug.

## Receive Buffers

I ran into receive packet collision (I thought I had fixed it???) and chunks of packets were being being received out of place.  
In hindsight, I'm not sure why I didn't just use something like [Socket.io](https://socket.io).
