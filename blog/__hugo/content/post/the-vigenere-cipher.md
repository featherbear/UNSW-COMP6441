---
title: "The Vigenère Cipher"
date: 2019-06-11T23:59:47+10:00

categories: ["Musings"]
hiddenFromHomePage: false
postMetaInFooter: false

flowchartDiagrams:
  enable: false
  options: ""

sequenceDiagrams: 
  enable: false
  options: ""

---

The Vigenère Cipher is a polyalphabetic substitution cipher, where a plain-text phrase would be encrypted and decrypted through a **keyword**, which would serve as a lookup for how many shifts would be performed on a character.

![](7850-004-C0E8DB7F.jpg)
Source: [Britannica](https://cdn.britannica.com/s:600x600/50/7850-004-C0E8DB7F.jpg)

Cool right!?  
_So how would you break it?_

# Kasiski test 
The Kasiski test lends itself upon the identification of patterns, repeated words and phrases within the cipher text - and the assumption that repeated segments represent the same plaintext segments.

This test helps to identify the possible key lengths, and suggests that the possible key lengths would be the distance, half the distance, a quarter of the distance, an eigth of the distance, etc ...

_i.e. if the distance was 16, the key could be 16, 8, 4, 2 or 1 characters long._  

A key length of one is just a Caesar Cipher

> _The idea is that probably such a repeated sequence comes from the same plain text sequence, which then randomly hit the same keyword position. They will only hit the same position if their distance is a multiple of the keyword length._  
\- Source: [StackOverflow](https://crypto.stackexchange.com/a/334)


# Index of Coincidence
\> [\*click\*](../index-of-coincidence) <