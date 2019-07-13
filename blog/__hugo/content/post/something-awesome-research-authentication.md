---
title: "Something Awesome: Research - Authentication"
date: 2019-06-15T16:47:24+10:00

description: "LET MEEE INNNNN"
categories: ["Assessments", "Something Awesome"]
hiddenFromHomePage: false
postMetaInFooter: false

flowchartDiagrams:
  enable: false
  options: ""

sequenceDiagrams: 
  enable: false
  options: ""

---

# Authentication - LET MEEE INNNN

![](https://i.redd.it/255iuxdit0g21.jpg)

Here are some possibilities of authentication mechanisms that I could implement:

## Password authentication

The venerable password authentication scheme. The only issue I see here is having control of the password.  
As the passwords will all be the same, once the password is compromised - all accounts will be compromised

## Device identification

We could generate a unique ID for each device; that once added to a connection whitelist - will grant unlimited future access.  
I would have to somehow check that the device ID hasn't been emulated.

## One-time password

As an additional layer of security, we could implement a [one-time password](https://featherbear.github.io/blog/post/2fa-one-time-password).  
Probably not ideal, but it could also be used as the first level of security, and not have a passsword (probably a bad idea).

Some node libraries are available:

* [`speakeasy`](https://www.npmjs.com/package/speakeasy)
* [`otplib`](https://www.npmjs.com/package/otplib)

[Authy](https://authy.com/) is a company that offers 2FA OTP service.  
They have these "Authy tokens" which are bound to your phone number.  
Perhaps this would be useful to register the 2FA secrets of RAT hosts.

* https://www.npmjs.com/package/authy
* https://www.twilio.com/verify

There are a few tutorials to set up 2FA OTP:

* https://www.thepolyglotdeveloper.com/2019/03/two-factor-authentication-totp-using-nodejs-speakeasy/
* https://www.thepolyglotdeveloper.com/2017/05/implement-2fa-time-based-one-time-passwords-node-js-api/

---

I'll probably use the usual password + 2FA OTP mechanism for authentication.  
Once the authentication is successful, I could use [JSON Web Tokens](https://featherbear.github.io/blog/post/json-web-tokens) for passing auth state.

On deciding which 2FA OTP library to use, I'm going to use [`otplib`](https://www.npmjs.com/package/otplib) over [`speakeasy`](https://www.npmjs.com/package/speakeasy) as it seems to still be under active development.

