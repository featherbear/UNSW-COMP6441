---
title: "Something Awesome: Component - Relay"
date: 2019-07-23T19:28:30+10:00

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

# It didn&apos;t work.

I was unable to perform a successful [NAT Holepunch](../something-awesome-research-connection) over TCP - which was a deadend for this feature.  

Whilst [NAT Holepunching](../something-awesome-research-connection) over UDP worked fine - I didn't want to create the relay knowing that it would only be half-working.

I do understand that there are other methods of establishing a direct Peer to Peer connection, but it was out of scope for this project, and I had already lost alot of time researching. Time would've been used better in developing the other components and features for this project.

Not having a relay just means that I wouldn't be able to main a list of connected servers.  
I can still connected directly from a Client to Server, without the Relay - so everything else would still work.

## Some Links

* https://sogilis.com/blog/tcp-nat-traversal-nodejs-stun/
* https://gist.github.com/mildred/b803e48801f9cdd8a4a8
* http://bford.info/pub/net/p2pnat/
