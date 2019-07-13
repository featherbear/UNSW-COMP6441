---
title: "Security Everywhere: DNS over HTTPS"
date: 2019-07-13T19:10:31+10:00

categories: ["Security Everywhere", "Musings"]
hiddenFromHomePage: false
postMetaInFooter: false

flowchartDiagrams:
  enable: false
  options: ""

sequenceDiagrams: 
  enable: false
  options: ""

---

Mozilla has 'recently' moved their DNS-over-HTTPS feature from the Testing to Release channel.

***What does that mean?***

Firstly let's start from the very basics.

# Context

> When you type `google.com` into your web browser, you see the Google search page!  
But in the background, your computer has contacted some _DNS server_ to query the _IP address_ for that _hostname_.

## IP Addresses

Computers on a network are accessible by what's known as an IP address.  
For example, your computer at home might have the IP address `192.168.1.114`. This is called your **LAN IP address** (LAN for _Local_ Area Network).  
If you're connected to the internet, you'd also have another IP, called your WAN IP address (WAN for _Wide_ Area Network).

Regardless, these address allow another computer to contact your computer.

Consequently, each website also has its own WAN IP address that we can go to in order to see the webpage.

For example, (one of) Google's IP is [`216.58.199.46`](http://216.58.199.46).  
And one of Facebook's IP is [`157.240.8.3`](http://157.240.8.35).

But it's not that easy to remember a specific IP address for each website that you want to visit - so that's why we have DNS!

## DNS

DNS stands for Domin Name System - and is the technology that allows you to type `google.com` into your browser, and see the page.  

What a DNS server does is return an IP address from a requested hostname.  
_In other words,_ if you request `google.com` it will return (in computer terms, 'resolve') the IP address `216.58.199.46`.

# The Issue

When you enter a website address into the browser, (if it has not already been visited) your computer will send a DNS query over the network and wait for a DNS server to return a resolved IP.

There are two issues here.

**1) Anyone can see the DNS request**  
If you're visiting some dodgy website, _anyone_ on your network will be able to tell that you've tried to visit that site.  
_Oh, and incognito won't help cover your tracks!_

**2) Anyone can reply to the DNS request**  
In fact this is common in MITM attacks, and is known as "DNS Spoofing".  
Anyone - including a malicious person - could craft a reply that says that `google.com` goes to _any_ address they choose.

These two issues are quite big concerns.  
With the premise of 'anti-terrorism' amongst other things, some governments may wish to censor and/or track your internet activity.  

But down to censorship and up for anonymity!??  

# Solutions

> In light of this post, I won't be talking about circumventing sites that are blocked on an IP level (_Your ISP could blacklist certain websites, so even if you memorise the IP address, it wouldn't do._), but rather focus on just DNS resolution

There are several ways that you could hide your DNS request traces.

* Memorise the IP
* Use a VPN
* Use a Proxy
* DNS over TLS / DNS over HTTPS

# DNS over HTTPS

DNS-over-HTTPS works by packaging the DNS request (and responses) in a HTTPS packet. The packet then looks just like any other HTTPS packet, and you wouldn't be able to deduce that it was a DNS request.

Supposedly only Firefox has this technology implemented.


> https://www.cloudflare.com/ssl/encrypted-sni/

