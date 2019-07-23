---
title: "Something Awesome: Project RATtata"
date: 2019-07-13T20:48:05+10:00

hiddenFromHomePage: true
postMetaInFooter: false

flowchartDiagrams:
  enable: false
  options: ""

sequenceDiagrams:
  enable: false
  options: ""
---

> [Go back to overview](../)

---

> View my presentation [here](https://featherbear.github.io/UNSW-COMP6441-RATtata/)

# RATtata

![](../rattata.png)

For my Something Awesome project, I developed a software-based RAT.  
Either a Remote Administration Tool, or a Remote Access Trojan - a RAT is a piece of software which allows you to connect to a computer remotely to perform actions and tasks. I decided to write a RAT because it would actually be useful to me as a piece of software that I might actually use in my personal life.

# Completion

## Core Features

|||
|:--|:--:|
|Client|&#x2714;&#xFE0F;|
|Server|&#x2714;&#xFE0F;|
|Relay Server|&#x274C;|

## Additional Features
|||
|:--|:--:|
|Keystroke Logging|&#x2714;&#xFE0F;|
|Electron GUI|&#x2714;&#xFE0F;|
|Display Streaming|&#x2714;&#xFE0F;|
|Cross Compatability|&#x2714;&#xFE0F;|
|Password Authentication|&#x2714;&#xFE0F;|
|Web Camera Capture|&#x274C;|
|Secure Communication|&#x274C;|
|Virus Reserach|&#x2714;&#xFE0F;|

---

I ran into several issues which occupied a lot of my time.

The main issue was trying to achieve NAT Holepunching for TCP, which prevented me from being able to successfully implement the [Relay component](../../something-awesome-component-relay). As a result of this I found myself running behind schedule - and consequently I ran out of time and was not able to implement a few of the additional features

_Kindly browse the other pages to find related issues._  

## Conclusion

Ultimately, I am quite pleased with what I have achieved in this project.

* I was able to write a piece of software that I can futher extend in the future.
* I was able to learn about NAT Holepunching, and other methods of establishing P2P connections.
* I was able to learn new technologies (Electron, Vue.js)
* I was able to perform a quite in-depth research about [Virus Behaviour](../../something-awesome-research-virus-behaviour)

Upon assessing my [project proposal](../../something-awesome-proposal), whilst I was unable to complete one of the three compulsory features, I am rather proud of being able to successfully implement the majority of other features that I had envisioned.

![](../screely-1563863889486.png)

# Pages

* [Proposal](../../something-awesome-proposal)  
* [Project Plan](../../something-awesome-project-plan)  
* [Technical Aspects](../../something-awesome-technical-aspects)
* [Research Plan](../../something-awesome-research-plan)
* [Protocol Specification](../../something-awesome-dev-protocol)

## Research

- [Authentication](../../something-awesome-research-authentication)
- [Connection](../../something-awesome-research-connection)
- [Display Capture](../../something-awesome-research-display-capture)
- [Keyboard Logging](../../something-awesome-research-keylogging)
- [Software Language](../../something-awesome-research-language)
- [Security](../../something-awesome-research-security)
- [Transport Layer](../../something-awesome-research-transport)
- [Keyboard & Mouse Emulation](../../_something-awesome-research-keyboard-mouse-emulation)
- [Webcam Capture](../../_something-awesome-research-webcam)
- [Virus Behaviour](../../something-awesome-research-virus-behaviour)

## Musings / Logs

- [Musings](../../something-awesome-musings)
- [Server](../../something-awesome-component-server)
- [Relay](../../something-awesome-component-relay)
- [Communication Protocol](../../something-awesome-component-communication-protocol)
- [Electron: User Interface](../../something-awesome-dev-gui)
