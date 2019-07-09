---
title: "Lecture 11"
date: 2019-07-09T10:30:21+10:00

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

[WEP]: ../wired-equivalent-privacy

# Initialisation Vectors (IV)

IVs are the so called 'seed' for an algorithm to start

--> What's wrong with [WEP]: The IV can be discovered

Seed: 40bit key + 24bit rng (IV) => 64 bit

Collision after sqrt(2^24) = 2^12

Keys vs Passwords (?):  

* Keys (in) bits of security
* Password (in) bits of data

---

In a 10 character long password, there are 80 bits of data.  
But not all of these bits can be considered for security

In ASCII, the first bit always 1.  
ASCII letters only up to around 119

Maybe only 10 * 7 bits

If lowercase only, perhaps there are only `10 * 5 = 50` bits - which is not secure enough.

---

# Data and Control

> **Post Office Analogy**  
Posting the purchasable items in the post office to yourself to avoid having to pay for each item.  
&nbsp;  
Are the items at the counter for purchase, or for postage?

[WEP] - Data and Control mixed

# Buffer Overflows

Ignoring multithreading and multiple cores, the 'parallel experience' we see is rapid context switching

Program interrupts add their task to the stack (including data as well as control information), and the stack pointer moves to the newest frame to run. When the frame is popped, the top of the stack needs to be 'reminded' of their state.

The stack is stored backwards, meaning that the next item in the stack has a memory address **earlier** than the previous stack address
```
# | Memory ===>
--|------------
1 | [A]
2 | [B][A]
3 | [C][B][A]  
```

If you write more data into `C` than the length, it will spill into `B`.  
i.e `3 | [C][C][A]`  

We could override the control data, which could change what the next step for the previous frame is.


# Proof of Work

> See more about [Cryptocurrency](../cryptocurrency)

A lot of work needed to compute and prove legitimacy

Whoever has the longest chain is considered to be the validated chain

If you were to falsify one of the previous ledgers, you'll need to race ahead to also falsify the next ones 

# Moore's Law

Transistors double each year, and compute power increases
