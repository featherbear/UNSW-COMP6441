---
title: "Something Awesome: Research Plan"
date: 2019-06-14T15:46:35+10:00

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

# Terminology

* **Host** - The target machine
* **Client** - The operator's machine
* **Relay** - A third server which aids in establishing a direct connection between the host and client.
* **RAT** - The software, in general context
* **sysRAT** - The software, in context of its use as a Remote Administration Tool software
* **malRAT** - The software, in context of its use as a Remote Access Trojan malware

# Research Plan

## For Compulsory Features

### Client / Server

* [Research what language to write the client and server](../something-awesome-research-language)
* [Research whether to use TCP or UDP, or a combination of both (or other?)](../something-awesome-research-transport)
* [Develop an application layer data protocol](../something-awesome-dev-protocol)

### Authorisation

* [Password authentication](../something-awesome-research-authentication)

### Display Streaming

* [Research how to capture screen data](../something-awesome-research-display-capture)
* [Research how to stream real-time screen data](../something-awesome-research-display-capture)

### Screenshot / Recording Capability

* Save screen data to disk

### Keyboard and Mouse Emulation

* [Research how to emulate keyboard input](../something-awesome-research-keyboard-mouse-emulation)
* [Research how to emulate mouse input](../something-awesome-research-keyboard-mouse-emulation)

## For Additional Features

### Relay

* [Research what language to write the relay](../something-awesome-research-language)
* [Research NAT holepunching](../something-awesome-research-connection)

### Secure Connection

* [Research encryption](../something-awesome-research-security)

### Keystroke Logging

* [Research how to record keyboard input](../something-awesome-research-keylogging)

### Webcam Capture

* [Research how to take a webcam still (or recording)](../something-awesome-research-webcam)

### Cross-Platform Support

* Ensure that functionality works cross-platform.

## For the sake of learning

* [Prettify the client GUI with Electron](../something-awesome-dev-gui)
* [Research how viruses work, and what behaviours they have](../something-awesome-research-virus-behaviour)

