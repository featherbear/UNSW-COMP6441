---
title: "Passwords"
date: 2019-07-02T00:00:54+10:00

description: "LET ME INNNNN"
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

<link rel="stylesheet" type="text/css" href="visualiser.min.css" />
<script defer src="zxcvbn.js"></script>
<script defer src="visualiser.min.js"></script>

Passwords and PIN codes...  

They're one thing you never disclose to anyone else... _(unless you're [password close](https://www.youtube.com/watch?v=4KwdwBvb4mQ) with your buddies)_  

It is the key to open up the doors of your life.  
Your email account, Facebook, your bank account, perhaps your [combination lock](https://www.youtube.com/watch?v=a6iW-8xPw3k).

Yet, despite its importance and so much being at stake when compromised - it's amazing to see how **bad** people's passwords are.  

# Common passwords

* `123456`
* `password`
* `123456789`
* `12345678`
* [`12345`](https://www.youtube.com/watch?v=a6iW-8xPw3k)
* `111111`
* `1234567`
* `sunshine`
* `qwerty`
* ...

It's _really_ concerning actually - if you have one of these passwords...  
**Please change it**

With the power of modern day computing, the prevalence of account hijacking has skyrocketed.  
Brute-forcing passwords (though inefficient) is very doable; and with attackers getting craftier, we need to be smarter and more aware.

# Good password practice

* Don't use words
* _Or_, use lots of words.
* Use a combination of lowercase, uppercase, numerical and symbol characters
* The longer the better
* Don't use the same password twice

> _"But, but, but... I can't remember so many passwords :c"_

You don't have to then.  

# Password Managers
**Password managers** securely store the credentials of your accounts, allowing you to generate arbitrarily long and strong passwords without needing to remember them!  
You only need to remember one password (known as the _master password_), which will give you access to all of your other credentials. Some password manager programs automatically fill in your account details into known websites - which can be really handy!
I personally use [KeePass](https://keepass.info/), as I have a bit of a concern with online password manager services.

On the topic of passwords, if you **forget your password** you often go through a password reset procedure where you verify the ownership of the account by either answering some security questions, or by opening a link sent to your associated email address.  
_Also you better hope that the [password reset functionality works](https://featherbear.github.io/UNSW-COMP6441/blog/post/openlearning-security/)_.

# Try it out
> More of a visual learner? Perhaps try out the password strength visualiser below[!](https://github.com/codrops/PasswordStrengthVisualization/)

<div class="passwordInput-wrap">
  <input class="passwordInput" type="text" name="password" id="password" placeholder="> Test your password here! <">
  <p class="passwordStrength" id="strength-output"></p>
</div>

<div class="canvas-wrap">
  <canvas></canvas>
</div>
