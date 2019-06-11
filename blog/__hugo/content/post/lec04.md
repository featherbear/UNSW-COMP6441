---
title: "Lecture 4"
date: 2019-06-11T18:17:14+10:00

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

* Vignere cipher (letters shifted by different amounts)
* _`sausageP` is a common comical term, Pegasus backwards._

[The Vigenere Cipher](../the-vigenere-cipher)

Enigma machine - different ciphers for each letter  
> TODO: How does the engima machine work (rotors)

# Work Ratio
Low effort for authorised access  
High effort for unauthorised access  

Aside: Calculating the number of bits of a number
---

When dealing with powers of numbers, if we multiply a number to a certain power with the same base number raised to a different power, we effectively add the powers together. In effect, we also add the number of dits

2^10 -> 1024 (4 dits)  
2^20 ~= 1 000 000 (7 dits)  
2^29 ~= 5 000 000  
2^30 ~= 1 000 000 000 (10 dits)
  
# One-time Pad
A one-time pad is a sort of vignere cipher, where each character of a plain-text phrase is shifted by a random amount.

But, the issue arises ... how do you communicate the key to the intended recipient?  
As soon as the secret key is leaked, the cipher text can be reversed.

...

// Number stations

# Freedom of Information (FOI)
There are Freedom of Information laws that allow the public to request certain information from a company or body.


# Type 1 and Type 2 errors

|Type|Prediction|Reality|
|:------|:--------:|:-----:|
|False positive (one)|Y|N|
|False negative (two)|N|Y|

There is always a tradeoff in wanting to minimise false positives, or false negatives.

## Dealing with these errors
Though dependent on the case (and outcome meanings), we often would prefer to minimise false negatives - as, in terms of consequences - they don't incorrectly dismiss an important test


...

> Read more: Bruce Schneier

