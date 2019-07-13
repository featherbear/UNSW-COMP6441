---
title: "Lecture 9"
date: 2019-07-02T11:22:59+10:00

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

* Don't write your own cryptographic algorithm.

# Wired Equivalent Privacy

WEP was a very flawed technology that was once used to encrypt and secure wireless network traffic. Since then, newer technologies like WPA2 (and soon WPA3) have been released, and is urged to use.

The payload data was encrypted by performing an XOR against an RC4 stream cipher.  
Whilst the concept of XOR'ing data was not the reason that WEP was vulnerable - the way that it was implemented was the reason for its downfall.

By capturing enough broadcasted network packets, the IVs could be discovered; rendering the 'unknown' sequence of RC4 bytes [determinable](https://en.wikipedia.org/wiki/Stream_cipher_attacks). With the sequence of bytes XOR'd against known, it was easy to decrypt the original data. 
_Two values that have been XORed by a third value can be XORed together to recover that third value._
        
## Mixing data and control

Having the payload data and control data sent in the same stream is dangerous, as modification to the control data (such as the destination address) may lead to sensitive information being sent to unintended parties.

This is something that WEP is also vulnerable to.  
By modifying the destination address in a TCP/IP packet, the access point would naively transmit the information directly to you.

# Read more

* http://www.opus1.com/www/whitepapers/whatswrongwithwep.pdf  
* https://www.oreilly.com/library/view/80211-security/0596002904/ch01s07.html
* https://www.paladion.net/blogs/wireless-security-how-wep-works
* https://www.paladion.net/blogs/wireless-security-cracking-wep
