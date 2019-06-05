---
title: "Case Study: The Deepwater Horizon Accident"
date: 2019-06-05T13:47:26+10:00

categories: ["Case Study"]
hiddenFromHomePage: false
postMetaInFooter: false

flowchartDiagrams:
  enable: false
  options: ""

sequenceDiagrams: 
  enable: false
  options: ""

---

> On 20th April 2010, a blowout (uncontrolled release of oil or gas) caused an explosion on a mining rig that killed 11 people, and caused the largest oil spill in US history

_What happened? What went so wrong..?_

TLDR
---
A whole collusion of factors caused the ultimate failure of the system.  
A single point of failure of failsafes (lack of electricity), inadequate monitoring and logging, bad communication, worker negligence, or possibly there were too many alarms.

One small issue snowballed into an avalanche of other bigger, badder problems. Failure was bound to happen, and so it did.

Gas entered where it should not have entered, and up into flames went the mining rig.


The nitty gritty
---

{{< youtube aN2TIWomahQ >}}

# Deep Water Drilling - how is it different
On-shore drilling has control of the wellhead under the rig.

All the control mechanisms were where the blowout preventer was. In the case of off-shore drilling, these controls would be 5000ft beneath the sea.  
Separating the sea from the shore, is 5000ft of open piping.

Once hydrocarbons enter the riser, they have a direct path to the surface.

# What happened

* 126 people on board 12 hour shifts; how was the handover of the crew executed.
* Long distance from the shore to the rig
* Different companies working together

# Technologies

* Dynamic Positioning - for the vessel to remain geographically stationary - there are powered thrusters. In the event of power failure, or insufficient thrust - the rig needs to detach from the blowout preventer, as well cut the drill pipe (with blind sheer ram)

* Blind Shear Ram - A failsafe used to disconnect (cut) the pipe and to block the hole openings in the event of emergency. It could only cut the drill pipe material, and nothing else. There was another shear ram beneath the blind shear ram that could shear anything (but was not deployed during emergency procedure)

# Concerns raised (Yellow Lights)
In designing the system in whole, alot of concerns were possibly overlooked and given the go-ahead.

* Casing design
  * Long string (cheaper) rather than a liner and tie-back - one less degree of safety
  * No lockdown sleeve
  * Single string over several formations of different pressure

* Cement design
  * Only 6 centralisers (springy things) were installed, Halliburton suggested 21
  * Big casing, small hole
  * Nitrogen foam cement
  * No cement-bond log

* Pressure tests
  * There was no sort of pressure test standard
  * Testing conducted too soon
  * LCM (lost circulation material) that was use convoluted the test results - lowered the pressure
  * Kill line was affected
  * 1400psi drill pipe, 0psi kill line - should have been the same

* Flow monitoring
  * Overcomplication of monitoring
  * Mud was being unloaded, and it was ambiguous as to how much oil was actually being delivered.
  * Difficulty in checking for leaks/faults.

* Ignition
  - Hydrocarbons
    * Could have been diverted through sides (out of the rig)
    * Was diverted through the separators (onto the rig)
  * Low presure oil --> high gas
  * The engines were fed with the abnormal levels of gas, causing it to overspeed the generator which then provided too much electricity.
  * Spark, boom.
  
* Blowout preventer
  * Blowout preventer was closed, but it didn't seal the well due to the loss of power.
  * Two ways to disconnect
    * Manual button 
    * EDS (Emergency disconnect)
  - It didn't disconnect
  * Loss of hydraulic pressure prevented closing mechanisms
  * Loss of electricity caused the dynamic positioning system to fail, drill pipe damaged the blowout preventer
  * Manual intervention of the ROV (remote operated vehicle) did not correct the problem area


# What went wrong

* Hydrocarbons entered the system (cement did not mitigate)
* Hydrocarbons were not detected
* Hydrocarbon gas ignited, causing loss of system power
* Power-dependent mechanisms and failsafes were turned off 

* BP and Halliburton in denial of being the responsible party

* Environmental factor - the pressure in the Gulf of Mexico required filling of the cement to be performed at a different atmospheric pressure than its operational pressure

* Well started to flow, drill pressure increased when it should have been decreasing.

* Fuel failsafes only controlled fuel through the inlet pipes, not from external fuel (ie through the surrounding environment)

# Improvement

* Avalanche effect -> Check for possible failures at each component independent of 'logic'
* Better system integration
* Implement a standards of test
* Dependence of electricity -> Failsafes
* Ensure that objects in the path of the blindsheer ram are actually shearable
* Redundancy of equipment - independent control
* Remote EDS
* Better monitoring and availability of data
* Engine / generator regulation
