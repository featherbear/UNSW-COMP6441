---
title: "Lab 5"
date: 2019-07-03T17:28:31+10:00

categories: ["Labs", "Case Study"]
hiddenFromHomePage: false
postMetaInFooter: false

flowchartDiagrams:
  enable: false
  options: ""

sequenceDiagrams: 
  enable: false
  options: ""

---

Collision occurences > Birthday occurences => B R O K E N

# Example Question

> You have a password file of 1,000 hashes.  
Assuming that 50% of the passwords used were weak passwords which can be found in a dictionary of 1,000,000 common passwords, and that hashing a password takes 12 bits of work on average, roughly how many bits of work would it take to discover all these 500 or so weak passwords?

## Approach

* For each password [2^20 bits of work] (1000000 is close to 2^20)
  * Hash password [2^12 bits of work]
* For each hash [2^10 bits of work] (1000 is close to 2^10)
  * Compare

So 2^32 => `32` bits of work to hash them all,  
and 2^10 => `10` bits of work to compare the hashes.

We only really consider the 2^`32`, since 2^`10` has such a small magnitude when added.

So, `32` bits of work.

_We ignore the "500" passwords since we have to check basically all of the passwords_


## Working

---


# Case Study: Electronic Self-driving Cars

**Pick your side.**  
Either the CTO of an autonomous driving car company, or as a minister of your government.

## Concerns for the Assets of the Country

* Jobs (Public transport, taxi services)
* Infrastructure (roads)

## Top risks

* **Security**
  * Denial of Service // Jamming
  * Hacking and Car Hijacking

* **Computer Brain**  
_How well can we trust "computer vision"_  
  * My life, or theirs?
  * Incident response - What happens when an accident happens, or if there is an object on the road?
  * Who is in control of the vehicle

* **Jobs**  
An increase in convenience of private transport will lead to a decline of public transport usage, but an increase in technical jobs

## Preventing risks

* **Security**  
  * Securing wireless networks
  * Securing internal computers
  * Securing physical components

* **Computer Brain**  
  * What model will you go for when it comes to situations that are difficult to decide?  
  * Manual override for when the passenger wants to take control?

* **Jobs**  
The occupation world is _unstable_ and _always changing_.  
&nbsp;  
Will lead to an increase in technical jobs - _ie service people_  
But will also lead to job loss - specifically for those who operate public and private transport services.

## Verdict

_Yoooo are we left wing or right wing :')_  

No - is autonomy the way to go?  
Who is in control of the vehicle?

Does the convenience outweigh risks?  
Should it even be a comparison?

---

# Class Disussion

## Assets

* Company image, reputation
* Software & technology
* Finance

* Jobs and Growth
* Privacy
* Infrastructure
* The people (customers)

## Risks

* Security
  * Car hijacking
  * Insider attack
  * Corruption
* AI morality
* Money
* Legal issues - who's to blame?

## Response

* Minimise the attack surface
  * Less wireless capability (reduce remote hijacking)
* Allow passengers to drive the vehicle (override)
* Government watchdog / supervise the compnay
* Adding requirements to testing / standards
