---
title: "Lecture 2"
date: 2019-06-04T18:07:31+10:00

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

Threat Analysis // Case Study

* What can we learn
* How could we have known earlier


Dits - decimal digit (number of digits to represent a decimal) (ie 1000000 is 7 'dits')  
Bits - binary digit


# CIA Properties

## Confidentiality  

The data is secured and private  
(ie by encryption)

## Integrity  

Correct of the data  
(the data has not been modified)

## Authentication  

Correct access to data


---

- Steganography - hiding the existence of the message 

* Secrets are only secrets when not distributed.


# Code or Cipher?

* Codes - Arbitrary mapping  
* Ciphers - Patterns

* Substitution Cipher  
* Caesar Cipher - Shift each letter by `n`  
* Transposition Cipher - Shift letter position

> Fun fact: Code Talkers were native people used to communicate messages during war. They were effective as their native language was almost impossible to understand without immense practice.

---

# Kerckhoff's principles

**The main one** - A cryptographic system should be designed to be secure, even if all its details, except for the key, are publicly known.

* The system must be practically, if not mathematically, indecipherable;
* The algorithm should not require secrecy, and it should not be a problem if it falls into enemy hands;
* It must be possible to communicate and remember the key without using written notes, and correspondents must be able to change or modify it at will;
* It must be applicable to telegraph communications;
* It must be portable, and should not require several persons to handle or operate;
* Lastly, given the circumstances in which it is to be used, the system must be easy to use and should not be stressful to use or require its users to know and comply with a long list of rules.
