---
title: "Lecture 12"
date: 2019-07-09T18:08:32+10:00

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

> The extended security group for website security gave their presentation today. Here are my notes... from whatever they rambled on about: [link](../website-security)

> The cryptocurrency group also gave their presentation today: [link](../cryptocurrency)

---

# Block Ciphers

Block ciphers operate on a set size of data rather than on a per-byte basis. If there is not enough data to complete a block, padding is appended to the block.

## ECB - Electronic Codebook 

* Each block is encrypted/decrypted independently of other blocks

## CBC - Cipher Block Chaining

* Each block is XOR'd with the previous encrypted block before being encrypted itself.  
* Cannot be encrypted in parallel
* Requires an IV for the first block

## CFB - Cipher Feedback

* IV is encrypted then XOR'd with the data to produce the cipher text
* Previous block is encrypted, **and then** XOR'd with the data
* For decryption, the IV is encrypted then XOR'd with the next block's cipher text (?)
* Cannot be encrypted in parallel

Can (suppoedly) cope with partial data loss (ie transmission error)

# JTAG

JTAG (Joint (European) Test Access Group) is a hardware interface standard to communicate with the onboard chips on circuit boards. Often used for programming and flashing, but can also be used as a serial console, etc...

---

# Factors of Authentication

* Something you know - ie password  
* Something you have - ie physical element
* Something you are - ie biometrics


_But, they're really all just something that you know._  
_And at the end of the day, the 'physical' information will somehow be transformed into ones and zeros..._

Once your biometric system is compromised, you won't be able to change your fingerprint.
