---
title: "ATM Machine Security"
date: 2019-06-21T17:25:04+10:00

categories: ["Musings"]
hiddenFromHomePage: false
postMetaInFooter: false

flowchartDiagrams:
  enable: false
  options: ""

sequenceDiagrams: 
  enable: false
  options: ""

---

> So uh, we call them ATM Machines,  
but the acronym for ATM is Automatic Teller Machine...  
&nbsp;  
So they're actually _Automatic Teller Machine Machines_!?!?

Anyway...

# ATM Machine Security

ATM machines are a common necessity for people who need to convenient withdraw money without needing to go to the bank.

![](Snipaste_2019-06-21_15-51-22.png)

This diagram explains the architecture of the ATM system. Each ATM has a computer inside it (supposedly Windows!?), and is connected to the banking network. Being a computer on the network, there is functionality for remote management and software distribution.

ATMs have a numerical keypad, used for the entry of your PIN and general navigation of the interface.

Okay that's enough, you've seen them before.  
How would you compromise an ATM?

# Attacks

## Physical | Cameras

Ye good ol' camera solution.  
These can be discretly installed anywhere around the machine, for example above the screen, or even right where the keypad is.

**Defense**  
Cover the touchpad. Duh.

## Physical | Card Skimmers

Card skimmers are devices which disecretely capture your card details.  

**Defense**  
Modern ATMs often have an obscurely shaped card ready, to prevent such devices from being installed securely.  
Additionally, the readers are translucent, and have a LED that lights up - So you would be able to see if there was some sort of malicious chip or device embedded.  

It's a good practice to always give a tug on the card reader to make sure that there's no devie installed.

## Physical | Heat Reading

A way that PIN numbers (or keypresses in general) can be read is through an analysis of which buttons were pressed.  
Our fingers have heat, which is transferred to other objects when we come into physical contact.  
And that means, with a heat sensor you would be able to deduce which keys were pressed; and in which order.

**Defense**  
Wipe the keypad after you use the machine.  
Additionally (or optionally) - press the keys with your clothing.  
Better yet, **press random buttons** (and press _all_ of them)

## Technical | Blackbox Attacks

Think of a blackbox on a plane. It does a whole bunch of stuff, but we don't really know what exactly.  
It's sort of like that with computer blackboxes - we don't know how it functions, but we ask it to do something, and it performs that task.

An ATM blackbox attack involves firstly physically compromising the ATM, and taking out the cash dispenser.  
The cash dispenser is controlled with digital signals which are sent from the ATM's logic board.  
By connecting the dispenser's cable to our own board, we would (theoretically) be able to issue the correct signal to the dispenser to give us the dosh.

But easier said than done right.

**Defense**  
According to [this video](https://www.youtube.com/watch?v=Rsx3JD2Rk-c), the dispenser unit has a three level multilayered encryption scheme.  
Basically that means, the command message is encrypted, then encrypted again, then encrypted another time.  
In order to forge the message, you would have to know all three encryption details... A very low chance.

## Technical | On-line Malware

Online malware attacks refer to attacks that are performed on a live system.  

The term _online_ refers to if a system is up/on or down/off, rather than if it is connected to the internet.  
This is probably the most common type of malware - _that is_ - the malware is opened by, and operates on the system which launched in.  
Now having access to the system, you would be able to gain remote access, and issue commands to be performed.

**Defense**  
1) Change your admin passwords  
2) Have a softwre restriction policy to whitelist programs  
3) Disable uneeded services and features  

I remember that Windows has a software restriction policy which you can set up to only allow certain files to run.

## Technical | Off-line Malware

Offline malware attacks refer to attacks that are performed on a system while it is offline.  
ATMs and computers alike, these attacks could involve rebooting a system to boot into a Live OS on a USB drive or DVD.  
One could then mount the system drive, and drop a virus in.

**Defense**  
1) Encrypt your drive. This way you won't be able to access the disk without the decryption key.  
2) Set up a password to access the BIOS settings (_and hope the CMOS battery has enough charge :')_)  
3) Configure your boot devices, and prevent unauthorised boot devices  
4) Secure Boot is a thing...


## Technical | Network MITM

MITM stands for Man-In-The-Middle - a form of eavesdropping and attack where you intercept messages (network packets) between two hosts, being able to read, or even modify the data.

*I made a [HTTP MITM demonstration](https://github.com/featherbear/UNSW-CompClub2019Summer-SecurityWorkshop/tree/master/http_mitm) for UNSW's CSE CompClub 2019 Summer Security workshop, but I never got around towards presenting it due to running out of time. hah!*

**Defense**  
It should be evident by now, but encrypt your data.  
Your hard drive, your messages, your encrypted messages, and even encrypted versions of your encrypted messages...  
You might also using a VPN  (though that too is encryption, built alongside with routing)

## Technical | Software Distribution

Distributed systems (even systems in the same area) often have their software managed by a software deployment system - where a package can be sent and automatically installed on each computer. (Think of the update centre on your smart phone, or laptop..)

An issue that we could run into, is if a malicious application were to find its way to the list of software that your computers would install...

**Defense**  
A common practice is to sign your packages with some sort of certificate file that can prove the authenticity of the package.

---

---

By the way, the Commonwealth Bank ATMs are actually really annoying.  
The audible feedback that is heard when the keypad is pressed, has a long enough delay to throw me off.  
So I keep a collection of 3.5mm jacks and plug them in to every machine I use :)  

It's safe!

I wonder though, would you be able to sidechannel attack an ATM machine?  
Maybe each keypad button produces a different tone.  

Maybe we could write and play music on the keypad...
