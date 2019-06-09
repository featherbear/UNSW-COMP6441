---
title: "Golf Balls!"
date: 2019-06-06T21:32:04+10:00

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

> Did you know: The average golf ball has 336 dimples?

You did, well of course you did!  
You didn't? Well _someone_ didn't attempt their crypto challenge.

---

This was the cryptic puzzle for the week on [NSA Crypto Challenge](https://cryptochallenge.io/):  

`QWS MYSTMKS KZHO RMHH WMC 336 IGEVHSC.`  
=> Solution:  
`THE AVERAGE GOLF BALL HAS 336 DIMPLES.`  

So, how would you attempt getting, well, that ^.  

# Step Zero (not a method)
Before you even start decoding the text, figure out the cipher.  

Is it simply a shift cipher?  
Or is it a vignere cipher, a transposition cipher, a substition cipher (<-- it's this one), etc...  

If you don't know it is, you're going to have a very very hard time trying to break it...

# Method One - Be smart
_(Arguably the best method if you don't know what to do)_  
_(Also probably the only actual decent method, except for [method five](#method-five-ascension)_

* **Identify the single letter words.**  
You've got one of two choices, "A" or "I" (well you could also have "O" too)

* **Identify the vowels.**  
[Almost](https://edawg878.com/forum/threads/make-a-sentence-without-vowels.11901/) all words (let alone sentences) contain vowels, so figure out which letters corresponds to a vowel.

* **Find frequent words.**  
In the English language we have many words that appear in most sentences, such as "the", "and", ...

* **Find and identify patterns.**  
In the English language, we have alot of commonly grouped letters.  
&nbsp;  
_ie_  
bi-grams: ly, ed, tt, mm, ss, nn, ...  
tri-grams: the, and, ing, ion, tio, nde, nce, ...  
&nbsp;  
We classify these terms as `n-grams`.  
&nbsp;  
So if we replace groups of letters, instead of single letters we would have a higher probability of breaking the code (faster)!

# Method Two - Be lazy
aka... BRUTE FORCE

Given that numbers are already pre-solved (already correctly mapped), we only need to consider the characters of the alphabet (26 letters).

So given a string, there will always be `26!` possibilities (`26` x `25` x `24` x ... x `3` x `2` x `1`).  
That's _only_ a number in the factor of 27 dits.  
That's _only_ 403291461126605635584000000 different combinations :)

```python3
import string
import itertools
import re

def try_bruteforce(code):
  letters = list(map(lambda l: l.lower(), set(filter(str.isalpha, code))))
  
  for perm in itertools.permutations(string.ascii_uppercase, len(letters)):
  
    current = code.lower() # Converts input to lowercase to keep track of which letters have been replaced
  
    for i in range(len(letters)):
      current = current.replace(letters[i], perm[i])
    
    current = list(current)
    for i in range(len(code)):
      if code[i].isalpha() and code[i].islower():
        current[i] = current[i].lower()
    current = "".join(current)

    yield current
 
for attempt in try_bruteforce("QWS MYSTMKS KZHO RMHH WMC 336 IGEVHSC."):
  print(attempt)
```

All we need to do is dump the output into a file and find the right combination!  
Don't worry, the file won't be too big, just around fifteen thousand yottabytes.  

I'm kidding.  
Don't do this.. 
Please...

# Method Three - Be smart AND lazy

The code for [method two](#method-two-be-lazy) is slightly optimised (replacing only `n` different letters instead of all 26 if there aren't enough letters).  
But it is **in no way smart or efficient** [in context](#method-five-ascension) of the problem.  

It's completely naive and doesn't factor in any letter combinations or any English language heuristics as I talked about in [method one](#method-one-be-smart).  
So, let's do that!

But I'm not smart so - thank you, next.

# Method Four - Find someome who IS smart and lazy

In late 2017 / early 2018 I remember stumbling upon [Lantern](https://github.com/CameronLonsdale/lantern/).  
It's a library to help break ciphers - though I'm not sure how great it is (It worked for me last time. It didn't quite crack the code this time)

```python3
from lantern.modules import simplesubstitution
from lantern import fitness

ciphertext = "QWS MYSTMKS KZHO RMHH WMC 336 IGEVHSC."

decryptions = simplesubstitution.crack(ciphertext, fitness.english.quadgrams)

for d in decryptions:
  print(f"{d.key}\t{d.score}\t{''.join(d.plaintext)}")
```

# Method Five - Ascension.

These code-breaking models all rely on the fact that we're cracking the _English_ language.  
If the plain-text phrase wasn't in English, we'll never find the answer!  
In the English language, the most frequent letters are `e` `t` `a` `o` `i` `n` `s` `h` `r` `d` `l` `u`  
(*\*nudge\** hey it's an actual [thing](https://en.wikipedia.org/wiki/Etaoin_shrdlu)).  

With enough encoded data, you could perform a frequency analysis to check if the plain-text was in English, then hopefully match the letter frequencies.

&nbsp;  
&nbsp;  

--- 

&nbsp;  
&nbsp;  

I remember there being a challenge question in one of my COMP1511 labs, where you had to decipher some text.  
Definitely wasn't for the feint-hearted, and indeed a challenge question.