---
title: "Attacking Locks"
date: 2019-06-18T18:00:00+10:00

categories: ["Musings", "Extended Security"]
hiddenFromHomePage: false
postMetaInFooter: false

flowchartDiagrams:
  enable: false
  options: ""

sequenceDiagrams: 
  enable: false
  options: ""

---

This week (week 3) during the evening lecture, one of the extended security workshop groups presented a talk about lock picking!  
A few technical hitches with the presentation, but nonetheless they did a great job!

They introduced different types of locks, and ways to counter them.

## Pin Tumbler Lock

![](https://i.kinja-img.com/gawker-media/image/upload/c_lfill,w_768,q_90/18c7sna7bc6spgif.gif)

One of the most common lock types is the pin tumbler lock.  
They're used in most padlocks, and door locks.

Essentially, when the correct key is inserted into the key barrel, the grooves on the key cause the spring-loaded pins to move into their correct place. When the key turns, as the shear line is unobstructed the barrel turns freely, opening the lock.

So, how would you break this lock security?  

* A systematic approach to lockpicking, would be to use a tension wrench (to apply a turning torque) with a pick.  
Effectively you work your way trying to lift the pins into place.  
At each stage, one of the pins will have the highest resistance to being moved - so we want to locate that pin and move it.

* Another method (pretty fun) involved shoving a tool called a _rake_ into the keyhole, and vigorously reinserting it and turning until the pins 'fall into place'

* _Bump keys_ are similar to the _rake_, and also aim to 'bump' the pins into the right position

* _Shims_ allow you to release the locking mechanism, overcoming the need to actually get the pins into the right position

* As lock components are usually magnetic, applying a strong opposite magnetic force on a lock may be enough to open the lock

## Combination Locks

![](https://www.kmart.com.au/wcsstore/Kmart/images/ncatalog/sz/4/42048404-2-sz.jpg)

Combination locks have a series of coded dials that allow you to specify a combination which unlocks the lock.  
We can break these by applying a constant force on the shackle, and turning the dial with the most resistance until we hear something 'click' into place (both audibly and mechanically)

# Electronic Locks

* Key wear and tear (weathered button markings)
* Thermal imaging (heatprint)
* Oil smudges
* RFID card -> cloning
