---
title: "Mid-Semester Exam: 2016s1"
date: 2019-07-05T23:18:26+10:00

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
(2 Marks)  
Which of the below best describes the concept of a NONCE?  
  
[A] A key which is only guessable by brute force  
**[B] A number which is not used again**  
[C] A random number or phrase  
[D] A salt value for a hash  
[E] An idiot  
  
  
# Question 1  
(2 Marks)  
Buffer overflows can affect the control flow of a program by?  
[A] Storing a negative number in an integer  
[B] Changing a loop counter  
[C] Overwriting a return address in the stack frame  
[D] Changing data in the heap  
**[E] All of the above**  
  
  
# Question 2  
(2 Marks)  
A MAC is designed to provide  
**[A] Neither Confidentiality nor Authentication**  
[B] Authentication but not Confidentiality  
[C] Confidentiality but not Authentication  
[D] Confidentiality and Authentication  
[E] A small hamburger  
  
# Question 3  
(2 Marks)  
Given a cryptographic hash function, which is most likely easier:  
**[A] Finding two different messages with identical hash values**  
[B] Given the hash of a message, finding the original message  
[C] Given a hash value, finding a message which hashes to that value  
[D] Given the hash of a long message, and the contents of the second half of the message, finding the first half of the message.  
[E] It's not this one  
  
# Question 4  
(2 Marks)  
If all of the 100 agents in a system need to be able to communicate with each other confidentially using an asymmetric cipher, how many distinct private keys would be needed?  
Note: only enter DIGITS in your answer (or else the automarker will mark it wrong.)  

**Answer: 100**
  
# Question 5  
(2 Marks)  
You are going to use a system based on Merkle Puzzles to allow other people to communicate with you securely even if you have never met or shared a secret before. You encode 1,000,000 messages, each consisting of a different 200 character english phrase and a different 80 bit Merkle key, each message encoded using a different 40 bit CDMF key.  
If someone has a system which can decode an CDMF ciphertext into a plaintext using a given 40 bit CDMF key in 1 billionth of a second, roughly how many seconds will it take them to discover a Merkle key to use to privately communicate with you on averge?  
Give your answer in digits only, and rounded to the nearest power of 2. So if you thought the answer was 70 seconds you would enter 64.  
Note: only enter DIGITS in your answer (or else the automarker will mark it wrong.) except you may use scientific notation for very big numbers if needed.  

* 1000000 messages
* 40 bit key encryption
* 1 billion keys each second

If we need to decrypt just one message, each key would have a higher chance of being correct.  
On average we can then consider 2^(40-1) = 2^39 keys to test against the messages

**Answer: (2^39)/(2^30) = 2^9 seconds = 512 seconds**


# Question 6  
(12 Marks)  

A bank has invented a new way of turning a message into a number - called a CDC code, and uses this as part of a process to verify messages with so called VERIFY codes.  
The bank authenticates and protects the integrity of its messages by computing a VERIFY CODE which is the CDC code of {password,message}  
I.E. The CDC code of a secret password with the message appended to then end of it.  
The Bank sends the resultant VERIFY CODE along with the message (but does not send the password of course!) All messages each day use the same password.  

Below is how a CDC code is computed:  
Start with the first character of the message, convert it into a code using the following table (only some values shown)  
```
{{{  
A->23  
B->47  
I->397  
L->507  
O->581  
P->635  
R->687  
U->763  
Y->901  
0->405  
1->73  
}}}  
```
Then multiply this by 521, mod it by 10000, add 450, mod it by 967, then add in the code for the next character, and repeat...  

For example the CDC code for the message "AU" is 216.  
Working:  
{{{  
'A' 23x521 = 11983  
mod 10,000 = 1983  
+450 = 2433  
mod 967 = 499  
+763 'U' = 1262  
x521 = 657502  
mod 10,000 = 7502  
+450 = 7952  
mod 967 = 216  
}}}  

You have intercepted the following messages and VERIFY CODES:  
{{{  
"PAYBOB100" has VERIFY CODE of 481  
"BILLBOB1000" has VERIFY CODE of 573  
"PAYROB1000" has VERIFY CODE of 301  
}}}  

What is the VERIFY code for "PAYBOB1000"? (enter digits only in your answer)  
Notice this question is asking for the VERIFY code not the CDC code.

Perform a length extension attack and add an extra "0".

**Answer: (((481 + 405) * 521) % 10000 + 450) % 967 = 122**
