---
title: "Lab 03 - Looking at Doors of Planes"
date: 2019-06-19T17:00:00+10:00

categories: ["Labs", "Case Study"]
hiddenFromHomePage: false
postMetaInFooter: false

flowchartDiagrams:
  enable: false
  options: ""

sequenceDiagrams: 
  enable: false
  options: ""

---

> Read the [case study](../case-study-plane-doors)  
Read the [reflection](../reflections-case-study-plane-doors)  

---

# Asymmetric Key Cipher

* Public key for encryption
* Private key for decryption

_i.e._ think of a padlock-able box - this is the public key.  
The private key is the only thing which can open the box


# RSA 

Encrypt: plaintext^e % n = cipher

c^d % n = plaintext

## Example question
`e = 7, n = 33`  

The cipher text is: `26 72 41`.

### Solution

n = pq (p = 3, q = 11)

phi(n) = (p-1)(q-1)  
       = 2 * 5 = 10

d*e % phi(n) = 1

d*7 % 10 = 1

d = 3


# Case Study

Ceate 5 recommendations to prevent similar incidents in the future.

**Examples**  

* Prevent unauthorised
* Allow authorised
* Crew policies
* Are co-pilots required?
* Who can go in?
* Manufacture design
* Ground control? -> how about **NO**.

---

# | How to get into the cockpit

## 1) Psychological assessment

## 2) Protocol

* Always at least two pilots in the cockpit
* External dual access to force the door entry
* Can only deadlock when two pilots are in the cockpit

## 3) Testing operational functionality

## 4) Private facilities for the cockpit crew

## 5) Hijack / Terrorist situation

* Silent alarm
* Honeypot unlock (possible notification to air traffic control)

## 6) If there is no response

* Override priority
* Override only works if there is no response from the cockpit after a timeout.

---

# Other Groups&apos; Response

* Dual keypad access
  * Two separate keys
* Passcode changes
* Psychological testing
* Private facilties
* Dual interaction to **deny** entry
