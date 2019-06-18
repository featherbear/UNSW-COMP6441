---
title: "Google Domains and HSTS"
date: 2019-06-18T02:23:13+10:00

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

[.dev]: (https://domains.google/tld/dev/)

My friend recently purchased a [domain name from Google](https://domains.google/tld/dev/).

I was trying to help them set up their HTTP(no-s) server, but - whilst entry on port 80 by direct IP worked; connecting to their domain name didn't work.  

Looking at what the browser did, it had automatically redirected me to the HTTPS address.

Why did it do that!?

_Okay, I was being dumb and forgot what I read when the Google TLDs were first released..._

On their website:  

> **Built-in security**  
We're making the web safer one [.dev] at a time. Every [.dev] domain is on the HSTS preload list, which makes HTTPS required on all connections. That means built-in security for you and built-in security for your customers.

HSTS (HTTP Strict Transport Security) is a mechanism that helps to mitigate HTTPS Protocol Downgrade attacks (These attacks make the client visit the HTTP version of a site, rather than the HTTPS version, which is secure.)

The [HSTS preload list](https://hstspreload.org/) comes built into many browsers, and is a list of sites that the browsers are forced to visit under a HTTPS connection - this includes my friend's TLD address [.dev].

So because of that, we were not able to access port 80.

Setting up the server for HTTPS/443 fixed the issue, and we were able to connect to server!

Because we were lazy, we used [nginx](https://hstspreload.org/) as a HTTPS proxy to the HTTP application server.
