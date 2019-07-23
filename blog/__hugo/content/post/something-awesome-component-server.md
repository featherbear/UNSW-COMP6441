---
title: "Something Awesome: Component - Server"
date: 2019-06-18T11:45:13+10:00

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

Before writing the server, I first had to write up the [communications protocol](../something-awesome-component-communication-protocol) for TCP and UDP connection between the client, server, and relay.

With that done, I then worked on implementing _actual_ functionality into the server.

---

# OS Compat: Windows

To install some packages, I needed `node-gyp`, which is a tool to compile C / C++ code into addons usable by Node.js.

```
$> npm install windows-build-tools
```

But it didn't seem to work, and just froze on one of its operations.

I solved it by installing a specific version from the production release.

```
$> npm install --global --production windows-build-tools@4.0.0
```

# Display Capture

I used the [screenshot-node](https://github.com/Kuzat/screenshot-node) library which had native support for Linux, Mac OS X, and Windows! Yay!

The native C++ code that it was written in writes the screenshot data into a file on the filesystem - although I needed it to be stored in the memory.

Instead of rewriting the code, I decided to write a wrapper to stream the file contents into a buffer so that the data itself could be passed between functions.
