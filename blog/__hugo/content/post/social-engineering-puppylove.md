---
title: "Social Engineering Challenge: Puppy Love"
date: 2019-07-17T13:23:34+10:00

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

[Puppy Love]: http://comp6445-curlybracket-letsmakeflagsgreatagain-curlybracket.bid/challenges/puppylove/puppylove.org.au/
[puppylove.org.au]: http://comp6445-curlybracket-letsmakeflagsgreatagain-curlybracket.bid/challenges/puppylove/puppylove.org.au/
[email]: http://comp6445-curlybracket-letsmakeflagsgreatagain-curlybracket.bid/challenges/puppylove/mail/index.php

Activity time - Social engineer two staff members of the ficticious company [Puppy Love] to retrieve flags!

# Task

* Recover the flag for the Facebook account through social engineering over [email]
* Recover the flag for a bank transfer through social engineering over [email]

---

First off, recon.

# Recon

Having a look at the website [puppylove.org.au], we've gotten the following software products on our technology stack:

* CMS: WordPress (4.8.6)
* Server: LiteSpeed

The other non-important stuff are Font Awesome, and jQuery - but there's nothing we can do with those things.

In fact... there's nothing we can do at all! What we're seeing is a static site, a clone of a WordPress page...  
But anyway this is a social engineering activity, so let's find some useful data!

_Note: Going to ignore the timestamps and pretend that the information and data is in 'present time'_

* David Quest
  * (e) david@puppylove.org.au
  * Operations
  * Likes microbrewing
  * Has two black pugs - Angela, Jessie
* Sarah Jenkins
  * (e) sarah@puppylove.org.au
  * Has a 3 years old son named James
  * Married to David
  * Has a beagle named Jasper
  * Instagram - `https://www.instagram.com/sarah.jenkins0583/`
    * James' birth date is 02/12/2014
    * Other dogs: Max, Bella
    * 04/06 -> Mark's 35th birthday - Husband???
* Facebook - `https://www.facebook.com/Puppy-Love-Australia-154384201787157` (inactive)
* Dog: Stella
* Business Address - 363 George Street, Sydney, NSW 2000

## Inferring

_What can we infer from our data about David and Sarah?_

* Dogs: `Angela`, `Jessie`, `Jasper`, `Max`, `Bella`, `Stella`
* David likes microbrewing - so possibly `Coffee`
* Child: `James`, `02/12/14`, `021214`
* Sarah's husband: `David`
* Sarah's _other_ husband (_!??_): `Max`, `040682`, `040683`, `0406..`, `040616`, `040617`

If there was some sort of password / secret password form, these keywords could be possible dictionary attack candidates.  
But this task isn't that hard :)

---

Red team, go!  
Note: I was lazy and didn't actually write full sentences. I had a hunch that this demo site was just looking for keywords (which it did).  
But it would be better practice to write actual proper emails.

_But who's got time for that? Trimesters yo._

# Facebook Flag

The Facebook link at the bottom of the website doesn't go anywhere, we so won't actually be attacking or finding information off Facebook.  
So let's try send an [email] to Sarah about the Facebook password.

**Sending an [email] with the keyword `sarah`**

> Hi  
I'm sorry - I don't understand what you're after.  
Can you send me another email and be a little clearer?  
&nbsp;  
Kind regards,  
Sarah

**Sending an [email] with the keywords `sarah` and `facebook`**

> Hi,  
I'm pretty busy at the moment and just checking email on phone - what is it you're after for the facebook account?  
Let me know and ill see what I can do  
&nbsp;  
Kind regards,  
Sarah

**Sending an [email] with the keywords `sarah`, `facebook` and `password`**

> Hi,  
Yep no worries.  
&nbsp;  
The facebook login details are:  
username: sarah@puppylove.org.au  
password: **COMP6441{MakeSureYouSetUpTwoFactorAuthToPreventThis!!}**  
&nbsp;  
Kind regards,  
Sarah

---

# Banking Flag

If we send an [email] to Sarah about `payment`s, we'll receive this response

> Hi,  
I'm sorry. I don't handle payments. You're better off speaking to David about that.  
Sorry I couldn't be more help!!!  
&nbsp;  
Kind regards,  
Sarah

So let's send it to David then!

**Sending an [email] to David, with no important keywords**

> Hey!  
Thanks for the email.  
What's this regarding? I'm a little behind on payments if its about that. Soz.  
&nbsp;  
Cheers,  
David

_Right, so he's a bit behind on payments - let's follow that up with him_

**Sending an [email] with the keywords `david` and `payment`**

> Hi,  
Sorry - I'm a bit busy at the moment and you know how I feel about doing payments over email.  
Can this wait until tomorrow? Or is it urgent?  
&nbsp;  
Cheers,  
David

**Sending an [email] with the keywords `david`, `payment` and `urgent`**  

> Okay. I understand - it's an urgent payment!  
I've just put the transfer through now on netbanking.  
&nbsp;  
The confirmation code is **COMP6441{paymentfraudisreal!}**  
&nbsp;  
Cheers,  
David

---

# Aside

We also get a variety of other [email] responses should you miss out on `k` `e` `y` `w` `o` `r` `d` `s`

> Hi,  
I'm sorry. This email looks random, suspicious and doesn't even look addressed to me.  
I'm going to delete it.  
&nbsp;  
Bye

&nbsp;  

> Sorry. I'm not sure who this is...  
I don't reply to emails from people I don't know.  
Sorry

# Conclusion

So we've recovered the two flags `COMP6441{paymentfraudisreal!}` and `COMP6441{MakeSureYouSetUpTwoFactorAuthToPreventThis!!}`.

How would you protect these things from happening?  

One idea would be to have a communication protocol, that in order to request something you must say it in a certain way.  
Though that would be vulnerable to an attacker who knows the protocol.

Two Factor Authentication (2FA) (_as hinted in the flag_) is another possible way to mitigate these attacks - by requiring another factor of identification to authenticate.  
For example, both David and Sarah could have a 2FA code attached to a physical device like their phones - making a remote attack much harder without access to their phones.

Perhaps you could also store the login passwords, [securely](../passwords#password-managers) that is.

_But at least it would've (could've should've) stopped someone like me trying to gain access during 5 minutes of my spare time_
