---
title: "Reflections - 7"
date: 2019-07-20T00:28:38+10:00

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

Exams, Assessments!!!
---

I took a bit of break from this security course this week, as I was falling abit behind in my other subjects.

# Lectures

This week's lectures talked about the [Diffie-Hellman Key Exchange method](../lec13#diffie-hellman), where by the magic of maths (exponents) you can confidentially derive a shared secret without having to transmit your private segment over the internet! That way a third party, even receiving messages - won't be able to (easily) find the shared secret. Huzzah!

The extended security students gave their presentation about [Bug Bounties](../bug-bounties) and [Pentesting](../,pentesting), which was sorta cool

# Something Awesome

I found a bug in my application protocol, some bytes are arriving in the wrong order or something - but it only happens when two events (that write to the socket) are fired at the same time. I wrote a buffer, but perhaps I didn't implement it right...

Otherwise, I've gotten keylogging and display capture working!  
I've started on the Client GUI with Electron - but it's really time consuming so I'll probably stop trying to make it pretty, and get all the core functionality out...
Also I'll start working on the Relay service soon - as that will require me to figure out how to practically perform a NAT Holepunch.
