---
title: "Final Exam: 2016s1"
categories: ["Musings"]

draft: true
date: 2019-07-05T22:12:41+10:00

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
Give a specific example demonstrating an attacker using a Denial of Service attack as a key part of a broader attack strategy. What was the purpose of the DOS part of the attack?  
(Ideally give a real example of an actual and well known attack)  

**DOS example:**  
Conference - Flooding the Q&A mobile phone with questions so that questions were opened up to the floor instead.

**Role the DOS phase played in the overall attack:**  
Gave a member planted in the crowd the ability to confront the panel and ask a question that would have otherwise been veto'd and or censored

# Question 1  
How many bits of security are provided by a passport photo or a thumbprint scan? Pick one of  
these two identification measures and estimate the number of bits it provides. Give  
reasoning and calculations to justify your number.  
Pick one  
[A] Passport Photo  
[B] Thumbprint Scan  

**Passport Photo**

Surprisingly, in the airport their "security camera" for facial identification is just a Logitech Webcam.  
At most they are dealing with a 1080p video feed. That's 1920 x 1080 pixels = 2073600 pixels to work with.  

Since our faces are square shape, in reality our body in the camera would only cover (at most) 1080 x 1080 = 1166400 pixels.  
Let's say that there is about 10% padding around our body in the camera - 972 x 972 = 944784 pixels.

Each pixel would usually have 3 bytes of data for the R G B values, but we'll just consider a single value for each.

944784 * 8 bits per pixel ~= 23 bits of security


<!-- # Question 2  
Suppose you were part of the original HTTPS protocol design committee back in the dim distant past.  
Why would you not use RSA to encrypt a HTTPS session?  
____________________________________  
____________________________________  
____________________________________  
How could you achieve Perfect Forward Secrecy in an HTTPS session?  
____________________________________  
____________________________________  
____________________________________   -->

# Question 3  
> Alice and Bob engage in Diffie-Hellman (m=33,g=2) with private secrets 5 and 8 respectively, but evil Mallory performs a man in the middle attack on them. Write out the steps in the protocol one step per line in chronological order, each line showing the number which sent and who it is from, and who it is to.
&nbsp;  
> In your answer write  
`{{{    `  
`A->B 45`  
`}}}    `  
to denote A sending the number 45 to B, where A represents Alice, B Bob, and M represents Mallory.  
State any assumptions you make.  

**Steps in the protocol**

```
{{{  
// m = 33
// g = 2

// 2^5 % 33 = 32
A->B 32

// 2^8 % 33 = 25
B->A 25

// Shared key is 25^5 % 33 = 32^8 % 33 = 1

}}}  
```

# Question 4  
> Explain how malware could survive the hard drive being reformatted and the operating system being reinstalled.  

If the hard drive is partitioned, the malware might lie in a partition that was not reformatted and hence still exist on the disk.  
For example, if the malware lay in the EFI / Boot Sector of the drive, a reinstall of an operating system would not actually modify that part of the disk.

Alternatively, malware that lies in a tampered BIOS firmware could exist as the BIOS lies in the system layer outside the OS layer. 

# Question 5  
> You chair the government panel considering the introduction of new mandatory data breach notification requirements for organisations and you have just finished reading all the recent public submissions. What are the main arguments for and against introducing such a requirement?  

For: 

* All breaches (and potential vulnerabilities) will be disclosed, and therefore action can be done to fix it
* (possible) Monetary incentive to research and test security

Against:

* Will put civilians in a state of panic every time there is a new data breach
* (if the actual data was posted) People's credentials are at risk
* (if there is a bug bounty) Sites are going to be attacked more, and probably also without consent
* Some people won't be bothered to notify regardless


What do you recommend? Yes  
I would recommend this notion of data breach notifications to be approved - as it is more important to be aware of vulnerabilities, than for people to momentarily be uncomfortable.

# Question 6  

> You are crypt-analysing an unknown ciphering device using a chosen plaintext attack.  
You know that an Initialisation Vector (IV) is being transmitted in the ciphertext (although you do not know which bytes of the ciphertext contain it). Therefore sending two identical plaintexts usually gives rise to differing ciphertexts. You are not sure if the IV is generated pseudo-randomly, or is a nonce.  
You send 2 billion identical single packet plain text messages, and generate 2 billion corresponding cipher text packets before you find a pair of ciphertext packets which are identical to each other.  

Is it more likely that the IV is generated pseudo-randomly or is a nonce? How big is it likely to be (in bits)?  
[A] Pseudo-random  
**[B] Nonce**

A PRNG does not need to ensure that its output is unique, and unless it has a very large keyspace, there would probably have been a collision before 2 billion generations.  

Estimate how big the IV is likely to be (in bits), and give your reasoning.  
Assuming we are using a nonce that hypothetically increases by one for every generation, if the nonce generated has been seen before, then it means that after 2 billion generations, the internal states have spilled back. (0b1111111 + 0b0000001 = 0b0000000)

So 2 x 10^9 ~= 2^31

Therefore, the IV is approximately 31 bits.

<!-- # Question 7  

> Suppose in the future UNSW computing students have spread all over the world and all printf() vulnerabilities and buffer overflow vulnerabilities in all software have been found and patched.  
List four different examples of Data/Control interaction style vulnerabilities which attackers will still be able to exploit. If you can think of more than four put the four most significant at the top of your list.  

* 
*
*
* -->

<!-- # Question 8  
Many operating systems and antivirus systems now give preferential treatment to code which is signed (for integrity and authentication) using an X.509 digital certificate.  
So malware authors would like their malware to be signed. List four ways they could manage to have their malicious code signed. If you can think of more than four, list the four most important first and the other ones below.  
___________________________  
___________________________  
___________________________  
___________________________  
___________________________   -->

<!-- 
# Question 9  
This Ruby code decrypts any (supposedly "securely" encrypted) Snapchat image in any phone's cache.  
(Note: You don't need to be able to program in Ruby, or indeed even to understand the syntax of Ruby, to answer this question. Your background knowledge of programming from Python or C is sufficient.)

```ruby
require 'openssl'  
ARGV.each do|a, index|  
data = File.open(a, 'r:ASCII-8BIT').read  
c = OpenSSL::Cipher.new('AES-128-ECB')  
c.decrypt  
c.key = 'M02cnQ51Ji97vwT4'  
o = ''.force_encoding('ASCII-8BIT')  
data.bytes.each_slice(16) { |s| o += c.update(s.map(&:chr).join) }  
o += c.final  
File.open('decyphered_' + a , 'w') { |f| f.write(o) }  
end  
```

You have been hired by Snapchat to improve their security. They ask you if they should move  
from AES128 to AES256. They have asked you to comment on whether or not an attacker will be  
able to carry out 128 bits of work.  
Prove, showing your calculations and assumptions, whether or not 128 bits of work is too much  
for an attacker to be able to do, and make a recommendation as to whether Snapchat should  
switch or not.  
_____________________________________________  
_____________________________________________  
_____________________________________________  
_____________________________________________  
What are the main two security weaknesses that this code reveals?  
Main weakness:  
_____________________________________________  
_____________________________________________  
Second weakness:  
_____________________________________________  
_____________________________________________   -->


<!-- # Question 10  
This question relates to the film Die Hard 2 which you watched in week13/stuvac.  
The Federal Aviation Administration (FAA) is the national aviation authority of the United  
States, with powers to regulate all aspects of American civil aviation. These include the  
construction and operation of airports, the management of air traffic, the certification of  
personnel and aircraft.  
Suppose the film was real (!!) and after the events depicted in the film the FAA appoints you  
to conduct an investigation into the events with the aim of making recommendations on the  
basis of lessons learned. What are the top 4 recommendations you would make within the scope  
of the FAA (e.g. so don't make military or drug trafficking recommendations). As usual put  
the most important recommendation(s) at the top of the list. Briefly justify/explain each.  
Recommendation 1  
_______________________________  
Justification  
_______________________________  
_______________________________  
Recommendation 2  
_______________________________  
Justification  
_______________________________  
_______________________________  
Recommendation 3  
_______________________________  
Justification  
_______________________________  
_______________________________  
Recommendation 4  
_______________________________  
Justification  
_______________________________  
_______________________________   -->

= Part B =  
This part is worth 30 marks and consists of two 15 mark questions. Answer both questions.  
# Question 11  
This question relates to the ABC news article  
"Singapore prepares to block internet access on government computers"  
(see supplied PDF from http://www.abc.net.au/news/2016-06-08/singapore-blocking-internetaccess-on-government-computers/7494498)  
Suppose the Australian government has set aside 100 million dollars to improve the security  
of government computers and that you have been appointed chair of the working party  
recommending how it is to be spent.  
The prime minister has asked you to consider this approach taken by Singapore (as reported in  
the article) and advise if Australia should do the same.  
What attacks is this protecting against?  
___________________________________  
___________________________________  
___________________________________  
___________________________________  
___________________________________  
What attacks would not be protected by this?  
___________________________________  
___________________________________  
___________________________________  
___________________________________  
___________________________________  
Give the 3 main factors in favour of Australia doing this:  
___________________________________  
___________________________________  
___________________________________  
Give the 3 main factors in favour of Australia NOT doing this:  
___________________________________  
___________________________________  
___________________________________  
Make your recommendation  
Should Australia do this YES/NO?  
______  
(marks are for reasoning not for your particular recomendation)  
Explain your reasoning for making this recommendation  
_____________________________  
_____________________________  
_____________________________  
If you recommended YES explain with reasons how you would implement such a system within your  
100 million dollar budget.  
If you recommended NO give with reasons the main alternatives you recommend to do to protect  
the security of government computers with your 100 million dollar budget.  
_____________________________  
_____________________________  
_____________________________  
_____________________________  
_____________________________  
_____________________________  
# Question 12  
Consider the following flawed communications protocol intended to provide a zero knowledge  
proof to person V that person P knows a solution to a particular sudoku puzzle.  
>= Terminology: CELLS, ROW, COLUMN, SQUARE = 
{{{  
Say a solution is a 9x9 grid of CELLS each containing a single number.  
Say a ROW is a horizontal line of 9 cells in the grid  
Say a COLUMN is a vertical line of 9 cells in the grid  
Say the grid is divided into 9 non-overlapping SQUARES consisting of 9 cells of the grid  
arranged 3x3.  
}}}  
Step 1.  
P privately rearranges the cell values in each 3x3 square of their solution by moving each to  
a random different location in the same square, and then encrypts this into file S.1  
Step 2  
P privately rearranges the cell values in each 9x1 row of their solution by moving each to a  
random different location in the same row, and then encrypts this into file S.2  
Step 3  
P privately rearranges the cell values in each 1x9 column of their solution by moving each to  
a random different location in the same column, and then encrypts this into file S.3  
Step 4.  
P gives files S.1, S.2, and S.3 to V  
Step 5.  
V asks P for the key to one of the files and decrypts it, verifying that each digit 1-9  
appears exactly once in each square/row/column (depending on which file they have chosen to  
decrypt)  
Step 6.  
Repeat 1-5 until V is convinced.  
Is this a zero knowledge protocol YES/NO?  
______  
If YES prove it is, if no state what the problem is.  
_____________________________  
_____________________________  
_____________________________  
_____________________________  
Does this protocol demonstrate that P knows a solution YES/NO?  
______  
If YES explain why it does; if no state what the problem is.  
_____________________________  
_____________________________  
_____________________________  
_____________________________  
Give a correct communications protocol to provide a zero knowledge proof to person V that  
person P knows a solution to a particular sudoku puzzle. (Note we want a communication  
protocol not a physical protocol. It must be able to be conducted over the internet and  
cannot require P and V to be in the same physical location.)  
_____________________________  
_____________________________  
_____________________________  
_____________________________  
_____________________________  
_____________________________  
_____________________________  
_____________________________  
_____________________________  
_____________________________  
_____________________________  
_____________________________  
_____________________________  
Prove your protocol is indeed zero knowledge:  
_____________________________  
_____________________________  
_____________________________  
_____________________________  
_____________________________  
_____________________________  
_____________________________  
_____________________________  
_____________________________  
_____________________________  
_____________________________  
_____________________________  
<<BR>>  
<<BR>>  
= Part C =  
This part is worth up to 15 marks and consists of two questions.  
Answer ONLY ONE of the questions. They are not worth equal amounts.  
You are to choose which of these two questions, 13a or 13b, to answer but ONLY ONE ANSWER  
WILL CONTRIBUTE TO YOUR MARK. So don't waste your time and answer them both!  
(If you do provide partial answers for both questions just write at the top of your answer  
for Q13a which one you want us to mark. If you do answer both questions (please don't) and  
it is unclear which question you want us to mark we will mark 13b.)  
Remember answer ONE only of the following two questions.  
# Question 13a  
(15 Marks)  
ONLY ANSWER ONE OF THE TWO QUESTIONS IN THIS PART.  
HEY!! YES - TALKING TO YOU!  
A bank branch in the wild west of the Blue Mountains communicates with head office in Sydney  
using a telegraph wire that can be intercepted and which can be cut. So messages can be  
read, blocked and injected. To address this the bank uses a keyed MAC to guarantee  
authentication and integrity of the messages. The hacker Ned Kelly Junior intercepts some  
messages from the branch telling head office of deposits made by customers:  
{{{  
25052016130902105DEPOSITTODONALDKNUTH 16  
10062016090600100DEPOSITTOBUCKAROOBANZAI 31  
13062016191100042DEPOSITTOUNSWCOMPUTING1 3  
}}}  
He performs some transactions himself at the branch and his gang intercept these messages:  
{{{  
13052016090100025DEPOSITTONEDKELLYJUNIOR 5  
12062016090100100DEPOSITTONEDKELLYJUNIOR 22  
}}}  
He deduces that the messages are of the form  
{{{  
8 Digits : Date DDMMYYYY  
4 Digits : Time HHMM  
5 Digits : Transaction Amount DDDDD (in whole dollars ie no cents shown)  
The Phrase "DEPOSITTO"  
The Name of the Client (perhaps with digits on the end if there are more than one client with  
that name) this is of variable length  
A space  
The keyed MAC code in the range 0..32  
}}}  
The date and time are the approximate date and time of the transaction.  
After bribing some staff Ned Junior learns that the MAC is produced by appending a secret key  
to the end of the message and then computing a proprietary hash algorithm on the resultant  
combined message. The hash used by the bank is computed as follows:  
{{{  
0. initialise the variable "hash" to be 0.  
1. compute the "value" of the first letter of the combined message.  
* the value of a digit is that digit e.g. the value of "9" is 9.  
* the value of a character is the ASCII value of that letter e.g. the value of "A" is 65.  
2. update the hash variable using  
hash = (hash * 2 + value) mod 33  
3. repeat 1..2 for the second letter of the combined message, then the third, and so on until  
you reach the end of the combined message.  
}}}  
Ned Junior is not sure how often the key changes, there may be a new key each day, or it may  
only change at the start of each week, or each month.  
At 9am he deposits $100 into the branch and his gang intercepts this message:  
13062016090100100DEPOSITTONEDKELLYJUNIOR 26  
What is the likely security purpose of including the date and time in the message?  
_______________________  
_______________________  
What is a fake deposit message which could be injected by his gang which has the same keyed  
MAC value as this intercepted message, but which states that Ned has deposited $90000 not  
$100?  
_______________________________________  
# Question 13b  
ARE YOU SURE YOU WANT TO ANSWER THIS QUESTION?  
ONLY ANSWER ONE OF THE TWO QUESTIONS IN THIS PART.  
HEY!! YES - I'M TALKING TO YOU!  
(8 Marks - marked as pass/fail - no partial marks are awarded)  
Decipher the message below to work out what to type into the answer field.  
HQEET UTOII SNAEP MSRTT AOUIC DOINE  
OEPOH YCNAE UDIHP RCETH TAIES EWINR  
SCERS UNTGE IHUUT EFR  
Your Answer:  
__________________________________________________________n