---
title: "Something Awesome: Research - Connection Time"
date: 2017-01-01T00:00:00+10:00

description: "Establishing a connection over the internet"
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

# Connection Time - Establishing a connection over the internet

A client-server involves the client computer to be able to contact to a host over an open port on the internet.  

However,  
Dealing with firewalls can be tricky, especially when we have to deal with NATs.  

> In simplicity, a NAT only allows network packets to pass through it (gateway) if there is a request from a device on the private network. In other words, you won't be able to connect to a computer unless _they_ originate the request.  

Well that sucks... for a bit.

**NAT Holepunching** is a technique to establish a direct connection between two parties.  
Essentially, both parties establish a connection to a relay server.  
As they are both the _originator_ of the connection, the NAT will create routing rules to allow for inbound data.  
Now that a port is opened, this port information is then exchanged between the two parties.  
In other words, both parties now have a means by which they can directly communicate with each other.

This method good as it doesn't affect the nature of the underlying data (protocol agnostic), and does not require any further knowledge of the network topology, however there needs to be a third computer to function as a relay.

If we _don't want a third computer_, what we could do is reverse the roles of the client and server.  
Instead of having the local machine connect to the remote machine, the remote machine would initiate a **reverse connection** - and instead connect to the local machine.  
This way, we would not have to consider the firewall and network conditions of the remote computer, and thus only need to ensure that inbound connections are configured.

So the two approaches are:  

* A relay server to allow NAT hole-punching
* Run the server on the local machine, and have the remote machine to connect to the local machine

---

What's the better method?  

_malRAT payloads often have the operator's address hardcoded into the executable._  
The second approach (reverse connection) would be ideal for this as the endpoint would (most likely) be a static address. We could also hardcode a (sub)domain as a host address, which would allow for dynamic IP addresses of the operator's client (dynamic DNS).

But, this won't be good for the case when the client initiates a connection whilst on the go.  
Even if the operator was to update the dynamic DNS record, the updated record will need to propagate which takes time.  
Additionally, this doesn't deal with the client's network environment.  
_For example: Wireless broadband users are hidden behind a NAT, and are not able to (usually) open up ports to their computer_

In this case it's better to have a relay server.  
With the use of NAT Holepunching, we _should_ be able to establish connections from anywhere to everywhere.
