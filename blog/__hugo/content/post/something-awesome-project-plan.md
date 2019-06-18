---
title: "Something Awesome: Project Plan"
date: 2019-06-14T22:16:14+10:00

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

# Project Plan

* [Do research](../something-awesome-research-plan)
* [Write communication protocol](../something-awesome-component-communication-protocol)
  * Password authentication
  * Commands
  * Data payloads
  * Keep Alive
  * Hello
  
* [Write server](../something-awesome-component-server)
  * Listen to connections
  * Display streaming
  * Keyboard & Mouse Emulation

* [Write client](../something-awesome-component-client)
  * Connect to server address
  * Issue commands to server

* Additional
  * Client GUI
  * Write relay <!--[Write relay](../something-awesome-component-relay)-->
    * Listen for client connection
      * Connect to relay and try password
      * If authentication success, exchange server and client details
  * Keystroke Logging
  * Webcam Capture
  * Connection security (in the communication protocol)
  * Cross-platform
  * Virus behaviour
