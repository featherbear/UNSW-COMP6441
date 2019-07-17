---
title: "Lecture 13"
date: 2019-07-16T10:23:33+10:00

categories: ["Lectures"]
hiddenFromHomePage: false
postMetaInFooter: false

flowchartDiagrams:
  enable: false
  options: ""

sequenceDiagrams: 
  enable: false
  options: ""

---

# Diffie Hellman

> How can you establish a secret without transmitting it?

The Diffie Hellman _method (?)_ can be used to generate a shared secret without needing to transmit it. Note that this method is not for message encryption - only for secret generation.

It uses the maths properties of exponentiation:

* Use a generator number `g` ( known publically )  
* Then each party picks a random number `a` / `b` (private to them)  
* Send the other party `g^a` (or `g^b`)
* Receive the value and raise to your random number

This works as `(g^a)^b = (g^b)^a`

_Usually we would also decide a large prime number to be a modulo value `m` (so the values are restrained)_

* Good for establishing confidentiality, but it doesn't establish authentication.

# Vulnerabilities

* Vulnerabililty - A weakness in a system
* Exploit - Taking advantage of a vulnerability
* Bug - A mistake in the code of software

## Types

* // _Stack - Function data | Heap - Code and dynamic memory_

* Memory corruption - unauthorised modification to the memory
  * Buffer Overflow
    * Writing more data than the length of an allocated space
  * Integer overflow
    * Continuous incrementing of an integer could overflow it to become the largest negative value (or zero if unsigned)
  * Format string vulnerabilities
    * `printf` expects a format string as the first parameter.
      * Should do `printf("%s", "Hello World")` rather than `printf("Hello World")`.
    * Important because if we are passing in a string variable `printf(message)`
      * If `message = "%s"`, then the program will perform `printf("%s")`
        * The program will now search for the next 'given' argument
          * But we can then pass arbitrary information -> the next item in the stack
    * Can also use `printf` to write data into memory addresses!
      * `%n` - Write number of bytes to memory
      * `printf("1234567890%n", "\xDD\xCC\xBB\xAA")`
        * Write `10` into `0xAABBCCDD`

---

* Shell Code
  * Crafting a payload (in machine code) to open up a shell

* `NOP` sleds
  * SPAM THE MEMORY WITH `NOP`s
  * `NOP` is the assembly instruction to do nothing (pass)

<!-- TODO: `printf` vulnerabilities -->
<!-- TODO: Make an animation -->


# Assets

What are you protecting?  
What's important, what's not?  


## Identifying Assets

* Survey people
* Develop a plan
* Periodically revise

## Types of Assets

* Tangible - Products, items that can be valued
* Intagible - Morality, security, people - hard to value

