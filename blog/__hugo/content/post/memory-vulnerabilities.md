---
title: "Memory Vulnerabilities"
date: 2019-07-16T14:01:03+10:00

description: "Smash that stack!"
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

# The Toolkit - Attack Techniques

## Buffer Overflows

Buffer overflow attacks allow data to be written outside of their allocated memory space

> [Click here to read about Buffer Overflows](../buffer-overflows)

## Format String Vulnerabilities

Vulnerabilities in the `printf` function allow us to both read _AND_ write data in the memory

> [Click here to read about Format String Vulnerabilities](../format-string-vulnerabilities)

## Integer Overflow Attacks

So there's also integer overflow attacks, but it's a bit boring.

There will be a point where a number (due to its datatype) will overflow back to a large negative number (for `signed` types), or zero (for `unsigned` types).

With that we may be able to skip an error check - which could be bad.

# Mitigating Memory Vulnerabilities

Apart from writing better code, our operating system also tries to prevent bad stuff from happening. _But_ I said **try**.

> [Click here to read about Mitigating Memory Vulnerabilities](../mitigating-memory-vulnerabilities)

# Profit - Attack Outcomes

With the vulnerabilities, you would be able to exploit thing in many different ways.

By being able to **read program memory**, you would be able to possibly retreive passwords, secrets, and other things you shouldn't know

By being able to **write to program memory**, you could modify values, flags, change what functions will run, and even drop a shell!
<!-- 
http://www.vividmachines.com/shellcode/shellcode.html
http://shell-storm.org/shellcode/ -->
