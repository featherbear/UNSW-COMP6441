---
title: "Something Awesome: Proposal"
date: 2019-06-12T02:01:33+10:00
description: "I decided to make a RAT for my Something Awesome project..."

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

# Abstract / Introduction

_Remote Administration Tools_ help sysadmins and support staff to operate and/or troubleshoot remote computer systems wherever they may be.

Software like this exist, such as TeamViewer, Splashtop, Ammyy and PC monitoring agents like Pulseway. But none of these software really fully carry out all of the functionality that I occasional require - and if they did, I have to pay for it.

The term _RAT_ is also synonymous with the Remote Access Trojan malware, which is a remote administration tool created for malicious command and control (C&C) intent - such as identity theft, activity tracking and even ransoms

The task for this project is to create a **RAT** that can remotely connect to a computer, and perform remote operations (either in the foreground, or in the background, or both). Assume that the RAT exists on the host computer and can be executed when required.


# Compulsory features

* Server software that will listen to client connections
* Client software that can connect to servers and issue commands
* Access authorisation mechanism (password)
* Host display is visible to the client
* Keyboard and mouse emulation
* Screenshot capability

# Additional features

* Relay/broker server to manage running RAT hosts
* Connection is secured
* Cross platform support
* Keystroke logging
* Capture webcam photos
<!-- * Hidden execution -->
<!-- * Remote code execution -->

# If you&apos;re bored (worth no marks)

* Make the GUI for the client software pretty! (_Perhaps learn Electron_)
* Virus-like behaviour (self replication, auto-start)

# Task Outcomes

* Learn how to write client-server software
* Learn about networking
* Learn to implement third-party software libraries
* Gain experience in time management and problem solving
* Learn the basic characteristics and behaviours of virus and malware
* Make something awesome!

# Marking Criteria
HD - 85-100 - Compulsory features working with at least 3 additional features  
DN - 75-84 - Compulsory features working with 2 additional features  
CR - 65-74 - Compulsory features working with 1 additional feature  
PS - 50-64 - Compulsory features working  
