---
title: "Crypto Terms"
date: 2019-07-18T00:05:24+10:00

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

# Crypto Terms

* **Confusion** - Each bit of the ciphertext should be produced from a combination of parts from the key.  
This makes the identification of the relevant portions of the key difficult to find.

* **Diffusion** - A small change in the plaintext data will spread changes to the ciphertext. (change to 50% of the output bits)

* **Avalanche Effect** - _interchangeable with diffusion_

* **SP Boxes / Networks** - Substitution and Permutation Functions that are called cyclically (and are reversable)
  * **Substitution Boxes** - A(n invertible) mapping function to provide an output given an input
  * **Permutation Boxes** - A shuffling function to output a rearranged version of an input

* **Fiestal Networks** - A sort of one-way version of SP Boxes, where given the output it is difficult to find the input.
  * Given a reversed order of keys, it is able to decrypt with the same processes in encrypting.

* **Block Ciphers** - A cipher method which operates on blocks of data.  
The last block may need to be padded to match the required block size.

* **Stream Ciphers** - Each plaintext character is encrypted on a per-character basis (one at a time)
