---
title: "Index of Coincidence"
date: 2019-06-12T00:57:06+10:00

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


The _IC_ is a mathematical analysis of the relationship between letter pairs.

By comparing the IC to the IC of a known language (The IC for the English language is 1.73), we can more confidently identify the plain-text language of a cipher text.

To calculate the IC for a given text, you _do_ need a large enough sample space to analyse.

Ripped straight off from the OpenLearning course page:

> Sure you can compute the Coincidence index by counting the number of occurrences of each letter in the alphabet using a program and computing the formula directly (check out mr google for the formulae if you want to investigate that), but there is a fast manual trick developed in the pre-computer days for roughly estimating the Coincidence Index of a text.  
&nbsp;  
The trick: Print out the cipher text and line it up with a copy of itself, shifted a few places or by a whole line say.  Then count the number of times the letter in the first copy matches the letter it is aligned with in the second copy.  The number of such "coincidences" divided by the length of the message is a not-hopeless(tm) estimate of the coincidence rate of the text.  Multiply that number by 26 to get an estimate of the Coincidence Index.  
  
---

As a given exercise, we were provided with two different enciphered texts, and asked to determine which was encoded with a substitution/transposition cipher.

I decided that [this (wax-off)](https://de8964361f4bb909de8d-fe8b524ce0801bda0a4b2a48b0c06837.ssl.cf4.rackcdn.com/Z93zFDQU3VgcVhXKvgVudt4UgqPZzws6tFgHB6jPQPh4PrAPjyYshPN7KWwMno8f.1460089384/wax-off-GI-B.png) block of text was the correct one, as there were more frequent repetitions of letters

![](https://de8964361f4bb909de8d-fe8b524ce0801bda0a4b2a48b0c06837.ssl.cf4.rackcdn.com/Z93zFDQU3VgcVhXKvgVudt4UgqPZzws6tFgHB6jPQPh4PrAPjyYshPN7KWwMno8f.1460089384/wax-off-GI-B.png)