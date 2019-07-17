---
title: "Mitigating Memory Vulnerabilities"
date: 2019-07-16T16:04:53+10:00

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

# Mitigation

#### Stack Canaries

> In the past, the canary birds were used in the mining industry as an alarm system for if the gas concentration levels were too high underground.

Stack canaries exhibit a similar sort of use. They are arbitrary values located in the memory with the intention of never being modified. If they are modified (_i.e. as a consequence of a buffer overflow_) the application will halt before anything malicious might occur.  

In order to prevent detection by a stack canary, you would have to know the canary values, and rewrite them in during the buffer overflow.

#### No-eXecute bits

Application code is stored in the static section of the program memory, rather than the stack and heap.  
The NX-bit marks regions of memory as 'non-executable', as to prevent possible code in the stack/heap from running.

#### Address Space Layout Randomisation

ASLR is a technique to prevent attacking hard-coded memory addresses.  
By modifying the start address of the program, you would have to perform a sort of dynamic analysis to find the new variables.

<!-- ### Mitigating the Mitigations

#### Return Oriented Programming

* https://security.stackexchange.com/questions/20497/stack-overflows-defeating-canaries-aslr-dep-nx
* https://exploit.courses/files/bfh2017/day5/0x52_DefeatExploitMitigations.pdf -->
