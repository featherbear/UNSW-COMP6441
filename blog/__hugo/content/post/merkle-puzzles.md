---
title: "Merkle Puzzles"
date: 2019-06-18T17:34:37+10:00

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

Incoming copy pasta:

_Merkle puzzles are an approach to solving the difficult problem of key-distribution over an untrusted medium._  
  
_Let's say Bob wants to securely communicate with Alice._  

_Alice creates 1000 unique pairs of a unique Identifier, and a key:  1000 x (identifier, key)_  
_Alice encrypts each pair separately with relatively weak encryption - encryption((identifier, key), randomWeakKey)_  
_Alice then sends all 1000 encrypted blobs to Bob_  
_Bob chooses one encrypted blob at random and brute forces every password until it is cracked_  
_Bob is left with a unique identifier and a key. Maybe : (sausage, A3D19F)_  
_Bob encrypts the message with the key, and then tells Alice is he using the key corresponding to the ID 'sausage'_  
_Alice looks up 'sausage' on her list, and finds the corresponding key_  
_Alice decodes the message using the key A3D19F_

_For an attacker to intercept and decrypt their communications, they would require the corresponding key. Though an attacker can see the unique identifier 'sausage', they still don't know which key that ID corresponds to, as each of the pairs is encrypted._  

_The attacker is forced to brute force all 1000 encrypted packets until they discover the packet with the unique identifier 'sausage'. On some occasions they may be fortunate and discover the correct key on their first attempt, and on others they will be unlucky and have to brute force all 1000 packets. But on average they will decrypt the correct packet after n/2 times, or 500 packets._  


----

From this excerpt, I would summarise the Merkle challenge like this:

* **Party A** creates a collection of random identifiers are encrypted with a key, and sends this to **Party B**
* **Party B** cracks the encryption of one of the identifier-key pairs
* **Party B** sends a cracked-key-encrypted message with the cracked ID to **Party A**
* **Party A** looks up the key corresponding to the ID, and decrypts the message


---

# What&apos;s good

Because of the large number of ID/key pairs, it makes brute force decryption much harder.  
It works well for our **Party B**, because they have the choice of randomly selecting a ID/key pair to use.  

Third parties would have to guess that exact same ID/key pair, as well as to also crack it - to be able to get the key and read the plaintext messages. Really really really small chance (for a big big big range)

# What&apos;s (not) good

This is a rudimentary way of protecting data from being read, quickly.  
With enough time (or better technology), Merkle puzzles only delay the inevitable.

_But then again, you could technically brute-force a public/private key pair..._

I guess, there is a limit to how long something will take before it becomes [futile](../futility).

One thing you could do, is to have different collections of generated ID/key pairs that will generate faster than the time it would take to crack the key.

And of course, try not to reuse keys.

