---
title: "Reflections - Week 5"
date: 2019-07-13T19:52:09+10:00

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

> [Lecture Nine](../lec09) | [Lecture Ten](../lec10)

I wasn't able to attend the morning lecture as I went to an ELEC2133 crash-course. Halp.

We learnt about [Wired Equivalent Privacy](../lec09), about its implementation flaw of reusing IVs, and of mixing data and control in the same channel. The echo of **"Don't write your own cryptographic function"** resounded.

We also touched on [signing of documents](../lec10#signing-documents).  
Best best practise to sign documents, is to sign their hashes rather than the actual data contents.

# Extended Security

In the evening lecture, the extended security group for passwords presented workshop.  

> Have a look at this [post](../passwords).

Password hashes can be quite easily cracked when rainbow tables come into play.  
It's always a good idea to incorporate some sort of salt mechanism.

# Case Study

This week, we looked at the proposition for automated self-driving cars.  
In scope of security, there are many concerns and hazards that would not see for the approval of such an idea.  
For example, denial of service, carjacking, legalities during accidents, etcetera.  

At the end of the lab, we were informed that different groups had been given different scenarios.  
Some from the side of the government, and others from the side of the company giving the proposal.

It goes to show how [self-interest](../weakness-of-the-week-02) changes the way which you think.

# Something Awesome

Because of exams for other subjects, I'm now behind on my Something Awesome project, and I really need to give it a kick. Dattebayooo
