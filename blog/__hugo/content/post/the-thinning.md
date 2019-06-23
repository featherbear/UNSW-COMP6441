---
title: "The Thinning"
date: 2019-06-21T11:43:05+10:00

description: "The plot thickens, not nearly enough though."
categories: ["Musings", "Security Everywhere"]
hiddenFromHomePage: false
postMetaInFooter: false

flowchartDiagrams:
  enable: false
  options: ""

sequenceDiagrams: 
  enable: false
  options: ""

---

I got bored last week and watched [The Thinning](https://www.imdb.com/title/tt5254868/) (2016).

= Plot (**SPOILERS**) =

<details>

* Dystopia where the worst performing students are executed
* Protagonist (Laina) is very smart
* Deuteragonist (Blake) is the son of a presidential candidate
  * Blake is in love with a girl
  * Father doesn't like the girl
  * Father rigs the test so that the girl fails (and is sent for execution)
* Blake purposely sets himself to fail for the next exam
* Father rigs the test so that his son doesn't fail
* As a consequence, Laina's result is set to Fail - which made no sense to anyone
* Laina escapes and starts the reveal of the corruption scandal

</details>

I guess, this movie is one of the many possible examples of this week's [Weakness of the Week](../weakness-of-the-week-03) - where [corruption]((../weakness-of-the-week-03)) comes into play, through an abuse of power

But anyway, we're not here for a movie review - we be sec engies.

# What security measures were in place

* Watch towers - physical presence
* Guards - physical presence
* Lockdown - physical barricades to prevent entrance and exit
* RFID tags - to control room entry access
* Breach alarm - when the manual override was triggered

# Security Analysis

In one of the scenes, an officer confronted one of teachers who had aided Laina in escaping.  
He had asked her for her _name card_ and _ID tag_ - of which she had stolen the ID tag from another teacher). Because she was able to produce both artefacts, she was considered clean.

Let's look a little bit into this situation.  
She was able to get away with the situation because she had both artefacts.  
_But_ the ID tag **was not hers**.

With a name card, it's easy to check if you are who the name tag says.  
There's a photograph of you, as well as your name.

But for the ID tag, it was a key fob - and there are no visible markings to indicate who owns which tag.  

In order to have detected that the key fob was not hers, **there should be information encoded into the tag**, which the officer should have scanned and verified

---

Something _good_ at least, was the access to the server room.  
An ID card was required to enter the room - and even if the physical room was compromised - a password was required to access the terminal
