---
title: "Reflections - Week 6"
date: 2019-07-13T19:52:18+10:00

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

> [Lecture Eleven](../lec11) | [Lecture Twelve](../lec12)

# Lectures

_The lecturer was away today (get well soon!)_  

## Buffer Overflows

We learnt about [buffer overflows](../lec11#buffer-overflows), which is a vulnerability in the code where the length of user input isn't restricted. The data that exceeds the length of a buffer is naively written in the memory, overwriting data that belongs to other variables, registers, etcetera.

The tutors created a few challenges, you can see how to attempt them here

* [Challenge One](../buffer-overflow-01) - Overflowing the buffer to overwrite a flag variable
* [Challenge Two](../buffer-overflow-02) - Overflowing the buffer to modify the return address (address given)
* [Challenge Three](../buffer-overflow-03) - Overflowing the buffer to modify the return address (address not given)

# Extended Security

The extended security group for [Website Security](../website-security) and [Cryptocurrency](../cryptocurrency) gave their talks today.  

The website security talk was abit all over the place.  
Alot of things were just brushed over, and I had to explain what they just said to a few friends around me.

But nevertheless, they talked about XSS, CSRF and SQL Injection.

---

The cryptocurrency talk was more interesting - and even though I'm not very interested in cryptocurrency, I found myself learning something new!

# Labs

I wasn't able to attend my lab this week. But from reading other people's posts, it was a discussion on assets - To consider what things need to be protected, and how.  

> [Read my catchup lab notes](../lab06)

