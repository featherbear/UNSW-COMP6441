---
title: "Something Awesome: Research - Language"
date: 2019-06-15T14:41:33+10:00

description: "What language should I write my RAT in?"
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

# Language - What language should I write my RAT in?

In the search for what language I should write my RAT software in, I thought about the aspects:

* **File size**  
Ideally I want the file size of the final product to be as small as possible (_Don't we all?_).  
From a _malRAT_ perspective, a smaller filesize would mean a quicker distribution of the file.  

* **Environment**  
Does the host computer need certain software or dependencies to run my RAT?  
Does [Python](https://www.python.org/) need to be installed? Or the [.NET framework](https://dotnet.microsoft.com)?  
I would want the RAT to work as universally as possible.  
That also means cross-platform support, meaning that any OS-specific code needs to be abstracted.

* **Code Paradigm**  
Functional vs Object Oriented..  
Synchronous vs Asynchronous..  
There's never a right or wrong when it comes to decisions - but rather - it is selecting the best language to suit this project.  
&nbsp;  
A lot of the times when I have to deal with some sort of network interaction, I often stick to some sort of async / event-based paradigm.

* **Have I used thing language before**  
> In my TODO list, I have "Learn [Rust](https://www.rust-lang.org/)".  
Buuuut I probably don't have time to learn a new language on top of all of the R&D I'll need to do for the actual functionality of this RAT, on top of the other components of this course, on top of the other courses I'm doing.  
_Thanks trimesters._

---

I'm deciding to write it in [`node.js`](https://nodejs.org), as I've been using it for a while in my own personal projects.  

_Yes, I know,_ `node_modules`.

![](https://i.redd.it/tfugj4n3l6ez.png)
_Source:_ [_reddit.com/u/xaxaxa\_trick_](https://www.reddit.com/r/ProgrammerHumor/comments/6s0wov/heaviest_objects_in_the_universe/)

I'll aim to write the software with not too many libraries as to minimise the program's file size.

In terms of distribution, I'll be using [`pkg`](https://github.com/zeit/pkg) by zeit, to package the files into a single executable.


