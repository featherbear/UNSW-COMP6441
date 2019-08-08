---
title: "Lecture 19"
description: "Privacy in the modern age - we're stuffed"

categories: ["Lectures"]
date: 2019-08-06T10:12:20+10:00

hiddenFromHomePage: false
postMetaInFooter: false

flowchartDiagrams:
  enable: false
  options: ""

sequenceDiagrams: 
  enable: false
  options: ""

---

# Privacy

> Data is the new oil
---

* Very useful
* _But_ very dangerous

## Issues around data collection

* Data linking - correlating data sets
* (De)anonymisation
* Massive Scale
* Data breach
* Fishing expeditions -> Using data out of collected purpose

## Tools aren't built for users

Tools are often built for government agencies to easily retrieve your data.

## Who has your data?

Everyone tbh.

* Facebook
* Google
* Apple
* ...

## What data?

Location history, calls, emails, files, age, etcetera

## Who uses your data

* Private Companies  
* Government  
* Intelligence Communities

---

### Data Lakes

Pooling 'streams' of data into one big 'lake'.

# Think twice

* It's end to end encrypted
  - Malicious public/private keys might be added
* Algorithms not people
  - People
* Only does X under Y conditions
  - Bugs.
* It's locked down - only accessible by X
  - Rogue sysadmins (of data centers)
    - ie Snowden
* Thorough auditing
  - Oh.. do you now...
* Secure
* Anonymised

## Anonymisation Techniques

* Redacting
* Encrypting / Hashing
* Pseudonyms
* Binning (generalising the coverage)
* Statistical noise
* Aggregation