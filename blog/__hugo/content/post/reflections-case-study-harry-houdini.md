---
title: "Reflections - Harry Houdini"
date: 2019-06-12T17:09:17+10:00

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

> [Read up here](../case-study-harry-houdini)

So, [the readings](../case-study-harry-houdini) had like ***absolutely no relevance to the analysis question***, but you know what?  
That's okay, let's blame trimesters for that!

Supposedly, in foresight of Houdini's death, he devised a message protocol with his wife Bess, to let her be able to verify that - should his spirit speak - Houdini himself was speaking, and not words made up by the mediums.

***but no, the case readings had nothing about that.***

Anyhow...

So what would make a good message protocol?  
You would have to address the CIA properties

**Confidentiality**  
I guess, in context of Houdini's case - there wasn't really any confidentiality in the message, as it would be heard by many many many different people who had joined a seance. So we'll ignore this property

**Integrity**  
A good message protocol would have measurements in place to ensure that the message has arrived in its true form - that is, that the message hasn't been altered or corrupted in transmission.  

This would lead to ideas of some sort of checksum of each sentence

**Authorisation**  
How would you know if the 'spirit' talking to you was that of the spirit of Houdini, and not just some mumbo-jumbo that the medium was blurting out.  


---

Maintaining the integrity of a message, and validating the authorisation was the hardest challenge to consider for Houdini and his wife. How would you devise a system that is kept between two parties, and prevent any third party from deciphering?  

We can be reminded of Kerckhoff's principle, thate _even if the workings of a system is known, the message cannot be deciphered without knowledge of the key._

To achieve this standard, it meant that all means of security by obscurity would not suit the required protocol. 

In my tutorial group, we discussed that ultimately, the communication protocol should have a means by which the passphrase is always changing - sort of like a one-time password. _but, how could you effectively write an algorithm that can be performed by a human, espcially during the times of Houdini_.

At the end, the tutor suggested using a public/private key encryption method. Although it would be quite hard to do that during those times. Even today, asymmetrical encryption is a complex and longwinded topic to understand - definitely way too complicated for the people of that past!

