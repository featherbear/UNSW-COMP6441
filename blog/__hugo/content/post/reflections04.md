---
title: "Reflections - Week 4"
date: 2019-06-28T20:08:51+10:00

categories: ["Reflections"]
hiddenFromHomePage: false
postMetaInFooter: false

flowchartDiagrams:
  enable: false
  options: ""

sequenceDiagrams: 
  enable: false
  options: ""

---

> # Lectures

I feel like the lectures are abit chaotic.

For starters, TWO lectures of the same course, on the same day!? Aaah let the information from the first lecture settle in my brain for at least a day - ah well.

Secondly, the lecture is like a launchpad - which springs you into your own tangential investigations of the raised ideas and points. Self learning and research is great - if you have time - which I do not.

> # [Extended Security | Social Engineering](../social-engineering)

The extended security group for this week presented the topic of Social Engineering - "hacking the human" as you would call it.

Humans are often the weakest link in the line of defense.  
We just [_love_ to open random files](../something-awesome-research-virus-behaviour), leak details inadvertently, and keep doors open for random people.

Ya'll we dumb.

> # [Case Study: The Secret Project](../lab04)  

_External security, internal security, physical security, digital security, meta security, security for the security..._

This week, we were given time to individually think how to secure a site for a secret research lab - It's cool to see how everyone had different (and possibly even conflicting ideas) about how to keep the site secure.

My top ideas were to:

1) Time-lock the access to the system (only able to access data during working hours
2) Keep the external appearance of the research building modest - don't hold up signs saying "Break into me", but also don't hold up signs saying "You _can't_ break into me"
3) Surveillance (security cameras + nearby response unit)

Aaah, it's a Pandora's box.

There were many interesting ideas proposed by my peers, you can [read more here](../lab04).

> # [Weakness of the Week](../weakness-of-the-week-04)

This week we glanced at the topic of _Moral Hazards_.  
Doing (or not doing) something when your morality disagrees with your duty.  

Would you be as so trigger-happy, or would you [hold the line](https://www.youtube.com/watch?v=ep8eyIfG7Ik)?

> # [Hashes](../hashes)

Add a tad of modulo here, a touch of badly written code there, and voila - a vulnerable hash function!

We learnt about cryptographic hashes and its desired properties:

* Fixed length - A hash always has the same length
* One way - Extremely difficult to reverse a hash back to an input
* Uniqueness - Only a single input can produce a certain output
* Avalanche effect - A small change in input produces a large change in the output

A few of the attacks on hashing functions are:

* Preimage attack - Given h(m), we are able to find m
* Second preimage attack - Given m, we can find m' where h(m) = h(m')
* Collision attack - Find m and m' where h(m) = h(m')
* [Length extension attack](#length-extension-attacks) - Generating the hash of appended data by using the previous hash result

**Message Authentication Codes** validate the integrity of data, and often use cryptographic hash functions in their implementation. However as they are vulnerable to the above attacks, we often used **Hash-based Message Authentication Codes** (**HMAC**) instead, which has the functionality `HMAC = hash(key + hash(key + message))`.


> # [Something Awesome](https://featherbear.github.io/UNSW-COMP6441/blog/categories/something-awesome/)

I got my ['custom' network layer protocol working](../something-awesome-component-communication-protocol)!  

I've been dealing with the HTTP / WebSocket protocol so often these days that I had forgotten that TCP is stream-based, meaning that my payloads were combined in the buffer, and it was up to me to split the payloads into their own packets myself.

You won't really see any 'Wow' outcome from this feat - but it's a crucial cornerstone to the rest of the project.
