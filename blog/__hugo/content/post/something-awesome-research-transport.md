---
title: "Something Awesome: Research - Transport"
date: 2019-06-15T15:10:03+10:00

description: "TCP? UDP? Both? What else?"
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

> I should really take COMP3331 first maybe idk

# Transport - TCP? UDP? Both? What else?

There's a whole bunch of transport protocols, [as you can see here](https://www.iana.org/assignments/protocol-numbers/protocol-numbers.xhtml).  
We want to find the best transport protocol, which supports the transfer of data.  
(Although, I guess if you _[really want to](http://www.unixist.com/security/data-transfer-over-icmp/index.html)_ use a certain protocol, go for it...)  
The main transfer protocols that everyone knows are TCP and UDP.

**Transmission Control Protocol (TCP)**  
TCP packets are commonly used in alot of applications, as they provide ensure the arrival of packet, in order.  
If a TCP packet fails to reach the destination successfully, that packet would be retransmitted.  

**User Datagram Protocol (TCP)**
I would describe UDP packets as 'fire and forget'.  
Once the packet is sent, the packet goes around the internet until it reaches its destination.  
Or maybe it doesn't reach - then oh well, eh.  
We would use UDP packets when there is no crucial need for the arrival nor the sequence of packets.  

But what about some other protocols?

* **Stream Control Transmission Protocol (SCTP)**
  * [RFC4960](https://tools.ietf.org/html/rfc4960)
  * [SCTP vs TCP vs UDP](https://www.ibm.com/support/knowledgecenter/en/ssw_aix_71/com.ibm.aix.networkcomm/sctp_intro.htm)

* **Datagram Congestion Control Protocol (DCCP)**

* **Quick UDP Internet Connections (QUIC)**
  * Similar to TCP
  * Reduced connection setup overhead
  * Underlying UDP packets
  * Error correction at the QUIC level
  - Still WIP

---

As to not delve too deeply into the low-level workings of the RAT, but rather to actually _get it working first_, I'll just be using TCP and UDP.

TCP: Commands, Control Messages, Most Data  
UDP: KeepAlive, Poll, Display streaming  

For most things, I'll use TCP as each data packet will be important.  
For KeepAlive messages, polling, and display streaming, it's okay to miss some of these data packets.

