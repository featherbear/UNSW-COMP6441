---
title: "Something Awesome: Protocol Specification"
date: 2019-06-15T15:43:30+10:00

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

# Connection

## Connection to Host

* Client sends `hello` to host
  * If bad auth, return `r_hello`::false
  * Establish connection
* Every interval, client sends `keepAlive` to host
* Client sends command to host
  * Host returns command

## Relay

The relay server does not exchange party connection details unless a connection is authorised.  
The relay server only keeps a record of the host's details in memory.

* Client sends `hello` to relay
  * If no ID, return `r_hello`::false
  * Relay sends `hello` to host
    * If bad auth, return `r_hello`::false
    * Exchange connection details
* Every interval, host sends `poll` to relay
* Every interval, client sends `list` to relay
  * Relay returns `r_list`

# Messages

## Connection Messages

* `keepalive`  
Description: A periodic "Keep Alive" message. No reply  
Source: Client  
Destination: Host  

* `hello`  
Description: Connect and authenticate to a relay / host  
Data: ID, Password / other auth token  
Source: Client / Relay  
Destination: Relay / Host

* `r_hello`
Description: Hello response  
Data: true/false  
Source: Host / Relay  
Destination: Relay / Client

* `list`  
Description: Request the computers connected to the relay  
Source: Client  
Destination: Relay  

* `r_list`  
Description: Returns a list of computers connected to the relay  
Data: Object of computers
Source: Relay  
Destination: Client  

* `poll`  
Description: Broadcast presence to a relay server. Latency also recorded by the relay server. No reply  
Data: Public IP, Computer Name, MAC Address, RAM, CPU  
Source: Host  
Destination: Relay  

## Control Messages

* `display_setup`  
Description: Configuration for the display stream  

* `screenshot`  
Description: Take a screenshot of the host's display

* `control_setup`  
Description: Configuration for keyboard/mouse input  

* `control`  
Description: Input data for keyboard/mouse input

* `keylog_setup`  
Description: Configuration for keyboard logging

* `webcam_setup`  
Description: Configuration for webcam control

* `restart`  
Description: Reboot the host machine

* `shutdown`  
Description: Shutdown the host machine

* `lock`  
Description: Lock the host machine

<!-- * `shell` / `rce` - Access a shell / terminal (netcat) -->

## Data Messages (Response)

* `r_display` - Display stream data
* `r_screenshot` - Screenshot data
<!-- * `r_shell` -->
