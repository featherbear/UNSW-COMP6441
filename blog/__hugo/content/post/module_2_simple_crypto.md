---
title: "Activity: A Simple Crypto"
date: 2019-06-10T23:11:23+10:00

description: "A crypto challenge from module 2"

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

A new crypto challenge!

```
Type: Crypto
Description: Decrypt the cipher-text below to find the flag.

TGPRGWTADEKI HI3OYNODONAT ES4LOCIINTB} FC4LURSDTHO_ LO1IRYAEEIU_ AM{NOPBAVNT_

Format: Enter the flag with no spaces.  The flag looks like:

COMP3441{...} 
```

---

So first thing's first is to figure out a pat-wait I've seen this before...  
It's as if I've done this bef-oh.

[![](Snipaste_2019-06-10_23-18-44.png)](https://github.com/featherbear/UNSW-CompClub2019Summer-SecurityWorkshop/blob/master/text_steganography/interleave.py)

> Source: [github.com/featherbear/.../interleave.py](https://github.com/featherbear/UNSW-CompClub2019Summer-SecurityWorkshop/blob/master/text_steganography/interleave.py)

I've once written a script to both encode and decode these sorts of 'interleave' ciphers.  
(I've got no clue what they're really called...)

---

Basically, you take the first letter of each word,  
then take the second letter of each word,
then take the third letter of each word,
then take the fourth letter of each word,
and keep going until you get the answer...

_Let's try that shall we?_  


**T**GPRGWTADEKI  
**H**I3OYNODONAT  
**E**S4LOCIINTB}  
**F**C4LURSDTHO_  
**L**O1IRYAEEIU_  
**A**M{NOPBAVNT_  

The first column spells out `THEFLA`.

T**G**PRGWTADEKI  
H**I**3OYNODONAT  
E**S**4LOCIINTB}  
F**C**4LURSDTHO_  
L**O**1IRYAEEIU_  
A**M**{NOPBAVNT_  

The second column spells out `GISCOM`.

TG**P**RGWTADEKI  
HI**3**OYNODONAT  
ES**4**LOCIINTB}  
FC**4**LURSDTHO_  
LO**1**IRYAEEIU_  
AM**{**NOPBAVNT_  

The third column spells out `P3441{`.

If we chuck those three phrases together... we get `THEFLAGISCOMP3411{`.  
So rinse and repeat, until we finally get the answer: `COMP3441{ROLLINGYOUROWNCRYPTOISABADIDEADONTEVENTHINKABOUTIT}`

Easy!  
(We disregard the `_` characters, as they are just there for padding)

---

But, what does the answer mean?  

_"ROLLING YOUR OWN CRYPTO IS A BAD IDEA DONT EVEN THINK ABOUT IT"_, huh!?  

In essence; _don't_ try to come up with your own cryptographic method - because it's probably dumb and simple to break.  

... you might come up with a super fancy and weird encryption algorithm - only to realise that breaking it is **simpler** than creating it..  

Actual smart people have spent many many hours working on the cryptographic algorithms that we use everywhere these days.  
Yes, there are vulnerabilities in the implementation - _but_ on the whole, it's still better than something that I could come up with... :)
