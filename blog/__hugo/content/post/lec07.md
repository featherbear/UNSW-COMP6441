---
title: "Lecture 7"
date: 2019-06-25T10:26:59+10:00

categories: ["Lectures"]
hiddenFromHomePage: false
postMetaInFooter: false

flowchartDiagrams:
  enable: false
  options: ""

sequenceDiagrams: 
  enable: false
  options: ""

---



> _Q: If step A takes 10 bits of work, and step B takes 20 bits, then how much to do both steps A then B?_

Answer: 20 bits.  

```
8XXXXXXXXXXXXXXXXXXXXX
+   XXXXXXXXXXXXXXXXXX
----------------------
XXXXXXXXXXXXXXXXXXXXXX
```

---

# Bits of Security

// Bits of security
// Bits of work

26! -> 4 x 10^26
~90 bits

--- Brute force smartly

# MITM Attacks

-> Replay attack  
Capture the information, and retransmit it

Challenge Response :: Date / Time, ID.  
Ask for reply

Birthday attack

Collision is higher than you think

sqrt of the hash size

ie in 52 cards, sqrt(52) ~= 7; chance of collision after 7 cards