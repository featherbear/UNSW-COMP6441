---
title: "Reflections - Plane Doors"
date: 2019-06-19T19:00:00+10:00

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

> [Read up here](../case-study-plane-doors)  
[See lab discussion](../lab03)

Today's lab look at the security of airplanes - in particular the access to the cockpit of the plane.

How would you devise a mechanism to let authorised people in, and keep people out? And what happens in the event of an incident: a pilot going rogue, a faulty door, a plane hijack?

Many of the groups in my lab suggested similar things, of which I'll discuss here.

---
As the case readings had suggested, there is a mechanism for the cabin crew to open the cockpit doors with an override code, and there is also a method for the pilots to lock the doors should there be unwanted guests.

In the event that the pilots are unresponsive, there needs to be a way to enter. Supposedly though, if the pilots had locked the doors, the override code would fail. Perhaps, this **override code should have a higher priority** than the internal lock.  

Of course though, this would raise a security concern, as a malicious person who knows the code would be able to bypass the door lock. It could be a good idea to require two people to enter (possibly different) codes simultaneously in order to unlock the door. This would therefore require two people with malicious intent to be present.

Perhaps also, this override code would only work if there was no unlock/lock response from the cockpit.

---

**Private facilities** for the pilot and copilot may be a good idea, whereby they are isolated from the passengers. Toilets, snaccs, their own area. This would stop any 'lockout' issues, if they never had to leave their lounge.  
Or maybe even have the cockpit completely isolated from the passenger seats, where entrance to the cockpit is through a different external door - though this would make it impossible to attend to the pilots if something was to go amiss. (Also, MAN WOULD THEY FEEL LONELY)

---

Should a terrorist / hijacking situation happen, I thought of having a **honeypot** / false access system, where a special code into the keypad would signal a 'door unlocked' status, whilst the door actually remains locked. This would prevent the malicious people from entering; albeit only temporary until they figure out what it going on.

---

One other issue that was apparent, was the **lack of psychological assessment** of the pilots. How would you know if a pilot, or even crew member, has the psychological stamina to function autonomously and with integrity. It would be good to let staff undergo some testing to deem if they are (still) fit for service. Sure we don't want to dehumanise people by a 'test' - but it is also quite important to ensure that the workers aren't dodgy.

---

How would you protect against rogue pilots though?  

Hmm..



