---
title: "Something Awesome: Research - Display Capture"
date: 2019-06-15T22:04:15+10:00

description: "One two three... say cheese!"
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

# Single Still Frame

## &nbsp;&bull; bencevans/[screenshot-desktop](https://github.com/bencevans/screenshot-desktop)

Cross-platform support:

* Windows: ✔️
* Mac: ✔️
* Linux: ✔️ (Uses [`imagemagick`](https://imagemagick.org))

## &nbsp;&bull; Kuzat/[screenshot-node](https://github.com/Kuzat/screenshot-node)

Cross-platform support:

* Windows: ✔️
* Mac: ✔️
* Linux: ✔️

## &nbsp;&bull; johnvmt/[node-desktop-screenshot](https://github.com/johnvmt/node-desktop-screenshot)

Updated fork: [senzil/node-desktop-screenshot](https://github.com/senzil/node-desktop-screenshot)

Cross-platform support:

* Windows: ✔️ (Uses [`nircmd`](https://www.nirsoft.net/utils/nircmd.html))
* Mac: ✔️
* Linux: ✔️ (Uses [`scrot`](https://en.wikipedia.org/wiki/Scrot))

# Display Stream

## &nbsp;&bull; noffle/[screen-stream](https://github.com/noffle/screen-stream)

Requires ffmpeg to be installed. Whilst license permits it to be bundled, it's quite a big library.

Cross-platform support:

* Windows: ❌
* Mac: ❌
* Linux: ✔️ (Requires [`FFmpeg`](https://ffmpeg.org))

---


From what I see and understand, node.js doesn't have low-enough-level access to the computer's display.  
Instead, most projects turn to actually just be wrappers for native software builds (ie [`FFmpeg`](https://ffmpeg.org) and [`imagemagick`](https://imagemagick.org)).  

If I were to learn how to write my own desktop stream capture solution, a [question on StackOverflow](https://stackoverflow.com/q/49607791) recommended to use [Native Abstraction for Node](https://github.com/nodejs/nan).  

Before I give up though...

# Robot.js

There's a package called [`RobotJS`](https://robotjs.io/)


# VNC

Perhaps what I could also do is utilise an already-established protocol; like VNC.  
This would also let [keyboard and mouse emulation](../something-awesome-research-keyboard-mouse-emulation) work out of the box.

VNC uses the [Remote Framebuffer (RFB) protocol](https://www.iana.org/assignments/rfb/rfb.xhtml).  

A node.js implementation of the protocol exists here: [sidorares/node-rfb2](https://github.com/sidorares/node-rfb2).

<!-- * Client: https://www.npmjs.com/package/peer-vnc
* Server: https://github.com/megamsys/vnc_server -->

---

I'll try using [Kuzat/screenshot-node](https://github.com/Kuzat/screenshot-node), as it supposedly supports OS X, Linux and Windows.
