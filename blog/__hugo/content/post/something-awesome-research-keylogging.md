---
title: "Something Awesome: Research - Keylogging"
date: 2019-06-15T22:07:10+10:00

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

A keylogger essentially logs the keys that you press.

To implement this, I'm thinking of storing the key strokes into a file buffer.  
Every now and then (or upon request), this file would be sent to the client.  

It might be a good idea to log the timestamps of when keys were pressed, though that will add file size overhead for each keypress.

The [`iohook`](https://github.com/wilix-team/iohook) package does exactly what I need to do (It even captures mouse input!).

Done and dusted.

