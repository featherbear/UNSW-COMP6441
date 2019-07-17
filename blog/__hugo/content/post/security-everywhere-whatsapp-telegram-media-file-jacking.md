---
title: "Security Everwhere: WhatsApp & Telegram Media File Jacking"
date: 2019-07-17T22:16:45+10:00

categories: ["Security Everywhere", "Case Study"]
hiddenFromHomePage: false
postMetaInFooter: false

flowchartDiagrams:
  enable: false
  options: ""

sequenceDiagrams: 
  enable: false
  options: ""

---

Recently the security peeps at Symantec released a proof of concept attack of "Media File Jacking" on the Android platform - namely through WhatsApp and Telegram.  
They detailed how [images](https://www.youtube.com/watch?v=FHvkGUh8S_c), [documents](https://www.youtube.com/watch?v=bKBk6NBHw5s), and even [voice messages](https://www.youtube.com/watch?v=Xt5BI0gIwnw) could be intercepted and modified in the background.

# How

Android phones often allow you to insert a microSD into the phone as an expansible external storage. (And even if there's no physical slot on the phone, you might have a virtual external SD on your filesystem).

Compared to how application data is stored in the internal storage, all data on the external SD is accessible by any application. With write access to the card (*), that means that any application could add, delete, _and modify_ other files.

*: You do need to grant the application permission to write to the external card, but most of us would press Accept...

**By default**, media files for WhatsApp and Telegram will store their files on the external SD card - and there's nothing wrong with that; it's the intended use for the extSD. But because of that, a malicious program could modify these files... And that's what this proof of concept reveals.

By listening for changes in the WhatsApp / Telegram media directories, paired with listening to broadcasted notification intent events - malicious programs would be able to monitor when a file is created, and then programatically perform modifications to those files.

That's an issue, because WhatsApp and Telegram are often used due to people's trust in their security and privacy.

It's not fault of the application - the protocol they use to securely transmit the content from one device to another over the internet is amazing. **The issue is what happens _after_ transmission** (and before as well)

# What now?

Symantec has recommended **turning off the option to save media files to your device's external storage**. By the nature of how Android sandboxes applications in the internal storage, applications aren't able to access the internal storage data of other applications.

In the upcoming Android Q update, there will be a feature called "Scoped Storage", which will provide this same idea, but for external storage mediums.

_Also, don't install dodgy stuff in general..._  
_You probably don't need those "100 Free Wallpapers" applications - **looking at you mum**_
