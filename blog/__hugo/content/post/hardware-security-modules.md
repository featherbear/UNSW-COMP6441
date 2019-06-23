---
title: "Hardware Security Modules"
date: 2019-06-18T17:24:44+10:00

description: "For the sake of security"
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

A hardware security module is a physical device dedicated for performing cryptographic computations such as key management, encryption and decryption.  

Because of its crypto-only use, its hardware is designed to optimise all the operations it needs to do - without needing to worry about operation versatility (which would add more bloat and probably security vulnerabilities into the design)

What do I mean by this?  

_Consider a program that performs commands depending on the user input_

(Written in Python for readability)

```python3
# stub functions
def functionOne():
  pass # stub

def functionTwo():
  pass # stub

def functionThree():
  pass # stub

# program
message = input("Enter a message: ") # Enter a message: <enterYourMessageHere>
  if message == "dolphin":
    functionOne()
  elif message == "squirrel":
    functionTwo()
  elif message == "penguin":
    functionThree()
  else:
    pass # stub
```

Let's say that `message` will **ALWAYS** be `"penguin"`.  
We wouldn't have a need for `functionOne` and `functionTwo`, and we can remove it from the code

```python3
# stub functions
def functionThree():
  pass # stub

# program
message = input("Enter a message: ") # Enter a message: <enterYourMessageHere>
  if message == "penguin":
    functionThree()
  else:
    pass # stub
```

The program here - evidently - does less, but!  
If we had to physically implement this code on hardware - it would mean that we would need less physical circuit components, and could optimise the functionality to let it do what it does to the best that it could do :)

In the same way, by writing code (and creating a device) that specifically performs one task (or one category of tasks) - the device would be able to perform cryptographic operations much more efficiently.

---

You could consider a hardware security module as a sort of blackbox machine.  
_You give it an input, and it gives you an output._  
We don't need to know how exactly it works, and we don't need to in order to use it.  
Being external to our machine and our code, it provides both a physical and logical layer of separation.

Often (if not always?), these security modules are built from the ground up - completely from scratch.  
It may seem redundant to '<s>reinvent</s> reimplement the wheel', but knowing how many vulnerabilities have been exposed in processors; it's a safer bet.
