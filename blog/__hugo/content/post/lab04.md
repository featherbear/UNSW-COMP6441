---
title: "Lab 04"
date: 2019-06-26T17:10:16+10:00

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

# Bits of Security

2^10 = 1024 ~= 1000

For a 4 digit PIN code, there are 10^4 = 10000 possiblilities

10000 rounded to the nearest power of 2 is 8192, which is 2^13

--- 

A combination of four lowercase letters -> 26^4 

---

Example
---

A-Za-z0-9\ _  
26 * 2 + 10 => 64 characters

64^8 = 2^48 combinations for 8 characters  

(2^6 = 64)
So 64^8 = (2^6)^8 = 2^48 -> 48 bits of work 


----

# Case Study  

> Secret Project | How would you physically secure the site?

## Thoughts

### Meta Security

Firstly, **what makes a project secret?**  

* Leaking of the project would lead to a business loss (innovation)
* The project should not be known to the general public, nor to even the majority of the employees of that company.
* Most likely, apart from the team, only the CEO of the company will know.

Not only will there need to be physical security to access the site, knowledge of the site's location will also need to be secured. This would mean scrubbing the whereabouts of the location.

**NO STICKY NOTES WITH THE LOCATION, GOSH**  
The human is often the weakest link in the chain of security -  _we gullible_, _we dumb_.  
The less people who know about the secret project, the better.

### External Security

**High tech security**  
Gates, patrols, watchtowers - those won't suffice.  
As to not raise any suspicion or interest in the location, we don't want to show any giveaways that there is some sort of confidential activity going on..

Possibly a **'sleeper' building** would be a good idea.  
A house that looks like a plain ol' building, nothing fancy on the outside.  
Just a standard looking house.

**Security cameras & surveillance**  
Perhaps there should be offsite surveillance of the premises, with security guards positioned nearby, ready to deploy should there a need arise.

The security feed will need to be protected as well - don't want footage leaked!!!

### Internal Security

How would you protect the assets inside the location.

To protect the computers, computers should somehow be chained to the room.  

Computers often have Kensington or Noble locks - although they don't really protect you against someone with a bolt cutter.  
If you have the goal in mind, you can pretty much do anything.

For paper documents, they should be locked up in storage cabinets.  
Or in any case at least not left in the open, in plain sight.

**Intruder Detection Systems**  
Though these systems do not _prevent_ intrusion, they are a deterrent.  
If an alarm trips and goes off, it will probably induce a state of fear and anxiety to the intruder.  
They will be time-limited perhaps, if the detection system was connected to an intrusion response unit / team.

### Digital Security

**Passwords and Encryption**  
Passwords and encrypted data are pretty much synonymous when it comes to attacking.  
If you have the password, the data will be compromised.  
If you have the decryption key, the data will also be compromised.

Perhaps other intangible ways of securing data is required.  
For example biometrics - fingerprints, iris scans.  

Of course though, these biometrical methods are still 'keys' at their core - You would be able to 'bruteforce' a fingerprint or iris...  

_At the very end, these pieces of human data will end up as digital data, ones and zeros_

**Thin Clients, Servers**  
Maybe a solution to protect digital data is to not have any data stored on the computers - rather all of the data is stored elsewhere on a server.  
This server could perhaps be time locked, and will only allow client machines to connect to during working hours.

(If a project is top secret, you _probably_ shouldn't be working on it after-hours right, at least not in your own house?)

## Key Features

1) Time-locked data  
2) Sleeper building  
3) Surveillance  

**---** _and that's all I could write within 20 minutes_ **---**

---

## Discussion

### Access Systems

* Guards, ID
* Biometric Access Recognition
* Different sections of the bulding require different permissions
* Security check at the exit (hard to check for digital data)
* Changing access keys / passwords
* Security guard verifies the employee

### Asset / Data Protection

* Assets are alarm-tagged
* Corrupt the data on authentication failure
* Faraday cage the wireless network (prevent sniffing)
* Only access data within the premise, within working time
* Data not stored on computers

### Obscure / Volatility

* Security camera
* Hot desk - Employees move desk location
* Physically centre items in the middle of the room (panopticon security)
* Tinted windows
