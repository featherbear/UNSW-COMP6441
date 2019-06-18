---
title: "Lecture 3"
date: 2019-06-11T10:07:23+10:00

categories: ["Lectures"]
hiddenFromHomePage: false
postMetaInFooter: false

flowchartDiagrams:
  enable: false
  options: ""

sequenceDiagrams: 
  enable: false
  options: ""

---

> Security is an on-going process of strengthening defenses. As the defenses goes up, so do the attacks

* **Security by Design** - Security as a forethought, rather than as a response to an incident  
* **Single point of failure** - one goes down, there goes your system.  
* **Defense in depth** - design of multiple measures of defense.

_Firewalls... they only protect the system from outside. Once you've inside, firewalls serve no purpose_


# Primary Colours of being a Professional

* Trust
* Secrets
* Humans
* Engineering
  * Risk
  * Complexity

# Trust

* Who can you trust? --> __No-one__  
* What can you trust? --> __Nothing.__

There are two, say 'models' for trust systems:

* Bell LaPadua Model - Hierarchical classification of authority and data confidentiality  
* 'Ape' Model - Autonomy & free will

From the few minutes we watched in class of the movie [WarGames](https://www.imdb.com/title/tt0086567/), the launch of the missile was ultimately controlled by the hands of two people - humans. And ultimately, the success of the system's function boils down to whether or not both men turned the key.

This is a good thing, a `dual control` system. Two separate individuals would have to willingly perform an action - there could be no accidental mistake.

----

# Data destruction
> How do you _actually_ get rid of data?

Destroying a printed document [could be easy](https://featherbear.github.io/UNSW-COMP6441/blog/post/paper-shredders/). You'd [_just_](https://featherbear.github.io/UNSW-COMP6441/blog/post/paper-shredders/) cut it up... [\*cough\*](https://featherbear.github.io/UNSW-COMP6441/blog/post/paper-shredders/), but what about deleting digital data?

On a storage medium, deleting a file from a disk only removes the file entry the directory table, _not_ the physical platten (or flash). You'd need to write to the platten in a lowlevel fashion...

But what about online data? Once something goes online, you don't know what's been done with it. Deleting a post, doesn't truly remove it. It exists... just somewhere.


# Side Channel Attacks
Side Channel Attacks exploit a system through its external implementation and characteristic, rather than through attacks to the weaknesses of code or an algorithm.

For example, listening to the EM waves fluctuate as different CPU operations are performed; or monitoring the voltage differential, execution time, etcetera
