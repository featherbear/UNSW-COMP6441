---
title: "Reflections - Week 3"
date: 2019-06-23T11:15:23+10:00

categories: ["Reflections"]
hiddenFromHomePage: false
postMetaInFooter: false

flowchartDiagrams:
  enable: false
  options: ""

sequenceDiagrams: 
  enable: false
  options: ""

---

> [Lecture Five](../lec05) | [Lecture Six](../lec06)

# Lockpicking

A group of extended security students presented how to [pick locks](../attacking-locks)!  
Even as someone who knew how to pick locks beforehand, I reckon they did a pretty good job!

# Weakness of the Week

This week we touched on [corruption](../weakness-of-the-week-03) - Bending the rules imposed on us to gain an advantage over others.  
Its so intrinsingly intertwined with Week 2's weakness, [self-interest](../weakness-of-the-week02).  

Like a game of Teris, but not - we forcibly fit the pieces of society around us, rather than fitting ourselves.  
And because of that, there exists gaps and holes.  
Uncleared rows start to build up.  
And eventually, you lose - and everything you've tried to hide comes to light.

# Cryptography

We first discussed [**Merkle Puzzles**](../merkle-puzzles).  
In theory, a party cracks one code from a collection of many other codes.  
The key recovered from the code is then used as the code to communicate with the other party.  
Bruteforcing all the codes to find the correct key would be too timeconsuming and effortsome.

We then touched on asymmetric key cryptography - where you have two separate keys, one to encrypt, and another to decrypt.  
[**RSA cryptography**](../RSA-crypto) uses this idea, allowing us to express text as a string of encrypted text.

# Highs and Lows - Probability & Impact

> [Link](../highs-and-lows-a-game-of-probability)

We revisited the idea of 'low probability, high impact' events - Unexpected events that shouldn't happen; but if they do happen, would lead to drastic implications.  
The issue at hand is our [response towards emergency](../weakness-of-the-week-01) - where we only take action when something goes bad; and we completely overlook the fact that there is a risk in the first place.  

Just because a risk isn't likely to happen, it doesn't take away the impact of the risk.

# Case Study

This week we studied about [plane door security](../reflections-case-study-plane-doors).  
Read the separate reflections above ^

# 🐧🐧🐧

[How would you steal a penguin?](../how-to-steal-a-penguin)  
I reckon a giant jumping castle is the way to go 😎🤙👌

# Something Awesome

I started working on my [Something Awesome](https://featherbear.github.io/UNSW-COMP6441/blog/categories/something-awesome/) project.  
Step one to any project is research, and lots of it.  

**I'm pretty happy with my research on [viruses and malware](../something-awesome-research-virus-behaviour) - Definitely take a look at it (please)**

I did get bored of just researching though, and made a start on the implementation of the communications protocol

# Research

## ATM

I researched about how [ATMs are (in)secure](../atm-machine-security).  
Like any network enabled devices, ATMs can be vulnerable to remote attacks.  
And it supposedly running on Windows... yeah

## Hardware Security Modules

[**Hardware security modules (HSM)**](../hardware-security-modules) are external devices which perform all cryptographic operations so that you don't have to!

---

Oh, also [Google Calendar went down](../security-everywhere-google-calendar-outage) for a few hours this week - I'd assume it was some misconfigured deployment, but there isn't any publicly released technical analysis of what happened

Speaking of Google, their [domains force HTTPS](../google-tld-hsts) - which is cool!
