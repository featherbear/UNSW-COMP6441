---
title: "Lecture 8"
date: 2019-06-25T18:05:44+10:00

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

> [Social Engineering](../social-engineering)


# Hashes

* Preimage attacks - given h(M), find M
* 2nd preimage attack - given M, find M' where h(M) = h(M')
* Collision resistant - find two messages M and M' where h(M) = h(M')  

# Uses of Hashes

* Fingerprinting
* Passwords
* Proof of Work
* Commitment
* MAC


Avalanche Property
---
A small change causes about 50% of the bits