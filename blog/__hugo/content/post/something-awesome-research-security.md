---
title: "Something Awesome: Research - Security"
date: 2019-06-14T19:14:06+10:00

description: "Keeping data secured"
categories: ["Assessments", "Something Awesome"]
hiddenFromHomePage: false
postMetaInFooter: false

flowchartDiagrams:
  enable: false
  options: ""

sequenceDiagrams: 
  enable: false
  options: ""

---

# Security - Keeping data secured

There are two main ways to encrypt data

# Symmetric Key
A single key is used to both encrypt and decrypt data.  
The vulnerability of this mechanism, is that if the key were to be discovered by a third party, they will be able to both encrypt, but more importantly decrypt the data.  

# Asymmetric Key
Two separate keys are used in the process of encryption and decryption.  
The _public key_ is used to encrypt data,  
whilst a specific _private key_ is used to decrypt the data.  

This mechanism works well, as the key to decrypting the data (_private key_) is kept within one computer.  

---

Asymmetric key crypto performs slower than symmetric key crypto, so what commonly is done,  
is to combine both symmetric and symmetric encryption schemes.

A symmetric key would be generated for the encryption and decryption of application data.  
This key would then be encrypted with the other party's public key, and sent back to be decrypted with the private key on their end.

In application to this RAT, the private key will need to be random.  
This is because if the key were to be hardcoded into the software, you would be able to extract the key and use it decrypt data from other RAT sessions.
