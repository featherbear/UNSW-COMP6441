---
title: "Mid-Semester Exam: 2015s2"
date: 2019-07-05T18:16:25+10:00

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
  
# Question 0
Which of the below best describes the concept of a NONCE?  
[A] A key which is only guessable by brute force  
**[B] A number which is not used again**  
[C] A random number or phrase  
[D] A salt value for a hash  
[E] An idiot  

# Question 1  
(2 Marks)  
A canary is designed to protect against which sort of vulnerability?  
[A] Overflow into return address  
[B] Format string vulnerability  
[C] Buffer overflow on heap  
[D] Integer overflow  
**[E] All of the above**  
  
# Question 2  
(2 Marks)  
A MAC is designed to provide  
[A] Neither Confidentiality nor Integrity  
**[B] Integrity but not Confidentiality**  
[C] Confidentiality but not Integrity  
[D] Confidentiality and Integrity  
[E] An expensive laptop  


# Question 3  
(2 Marks)  
A MAC is designed to provide  
[A] Neither Non-Repudiation nor Authentication  
**[B] Authentication but not Non-Repudiation**  
[C] Non-Repudiation but not Authentication  
[D] Non-Repudiation and Authentication  
[E] It's not this one  

  
# Question 4  
(2 Marks)  
The hash of a message appended to the end of a shared secret is NOT vulnerable to a length extension attack if  
[A] MD5 is used to perform the hashing  
**[B] SHA3 is used to perform the hashing**  
[C] SHA1 is used to perform the hashing  
[D] ANY cryptographic hash function is used  
[E] NEVER. Such a hash WILL be vulnerable to a length extension attack regardless of which currently known cryptographic hash function is used.  
  
  
# Question 5  
(2 Marks)  
What is a CRYPTOGRAPHIC random number generator (RNG)?  
[A] A RNG which uses a key  
**[B] A RNG whose past outputs do not help you predict the next output**  
[C] A RNG whose internal state has at least as many bits as the key space  
[D] A truly random RNG which uses genuine entropy rather than being pseudo random  
[E] A RNG whose outputs are indistinguishable from the output of a collision resistant cryptographic hash function.  
  
  
# Question 6  
(2 Marks)  
Which one of the following letters is not one of the six letters most commonly appearing in written English?  
[A] T  
**[B] S**  
[C] O  
[D] N  
[E] I  
[E] A  
  
  
# Question 7  
(2 Marks)  
If all of the 100 agents in a system needed to be able to speak with each other confidentially using a symmetric cipher how many distinct keys would be needed?  

Each agent would need one key for each agent they contact (99 others).  
`99 + 98 + 97 + ... + 1`  
But communicating from A-B and B-A uses the same key, so we can half the result.

Use the sum of numbers formula `n(n-1)/2` to get  
**Answer: (99 * 98) / 2 = 4851**
  
# Question 8  
(2 Marks)  
On average how many hash computations would be required to perform a successful birthday attack on a 16 bit hash?  
[Give your answer as the nearest power of two to the number you believe is the correct value. So if you thought the correct value was 42 you would enter 32 as your answer since that is closer to 42 than 64 is.]  

<!-- A birthday attack can occur in roughly `sqrt(number of bits)` attempts.  
So for a 16 bit hash, sqrt(2^4) is 2^2 attempts -->

# Question 9  
(2 Marks)  
You are going to use a system based on Merkle Puzzles to allow other people to communicate with you securely even if you have never met or shared a secret before.  
You encode 100,000 messages each using a different 48 bit key.  
If someone has a machine capable of encrypting a message in 1 billionth of a second, roughly how many seconds will it take them to select a key to use to communicate with you on average? (give your answer to the nearest power of 2)  
Why does encryption time matter for selecting a key?  

For a 48 bit key, there will be (on average) 2^47 keys that would need to be generated to find the right key.  
The performance of `1 key / s^-9` is the same as `10^9 keys / s`.  

And, `10^9 ~= 2^30`

**Answer: (2^47) / (2^30) = 2^17 seconds**

  
# Question 10  
(2 Marks)  
You are going to use a system based on Merkle Puzzles to allow other people to communicate with you securely even if you have never met or shared a secret before.  
You encode 100,000 messages each using a different 48 bit key.  
If someone has a machine capable of encrypting a message in 1 billionth of a second, roughly how many seconds will it take them to discover the key someone else is using to communicate with you on average?  
(give your answer to the nearest power of 2)  

Open to debate I guess.  

If the same key is used for all of the messages, then it's the same answer as the previous - but I guess this is another question for a reason.  
If each message is encrypted differently, the more messages you have, the easier it is to find **just one**  

But, are we trying to crack all the messages, or just one?

The 'average case' would most likely to be cracking half of the messages, assuming that they are all encrypted differently.  

On average, you would have to try all keys against 50000 messages, around 2^16 messages.  

**Answer: (2^16) * (2^47) / (2^30) = 2^33 seconds**
  
# Question 11  
(2 Marks)  
Alice and Bob are using the Diffie-Hellman algorithm to generate a common shared secret. They pick prime 11, and a generator of 2. Alice privately selects 9 and Bob privately selects 4. What is their shared secret?  

Steps

1) Pick a prime (for modulo) `p` and a generator `g` (base)  
2) Pick a secret `c` (ie RNG)  
3) Compute and send `g^c % p`  
4) Use received token `t` and then `t^c % p` where `c` is _your_ secret  

```
p = 11
g = 2

A          | B
-----------|----------
a = 9      | b = 4
           |
g^a % p    | g^b % p
= 2^9 % 11 | = 2^4 % 11
= 6        | = 5
>>>>>>>>>>>|<<<<<<<<<<<
           |
t^a %p     | t^b % p
= 5^a % p  | = 6^b % p
= 5^9 % 11 | = 6^4 % 11
= 9        | = 9
```

**Answer: 9**
