---
title: "Format String Vulnerabilities"
date: 2019-07-16T16:01:37+10:00

draft: true
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

# Format String Vulnerabilities

`printf` is a great function. It allows us to print data to the terminal, and its variants allow us to print to other things too!

Let's take a look at `man 3 printf`.  
The function signature is `int printf(const char *format, ...);`.

It takes in a format string, and a number of arguments used the format string.

Generally to print out text, you would use:  
`printf("%s", "Hello World!\n");`

But that is abit cumbersome... We could also perform the same operation by doing:  
`printf("Hello World!\n");`

It's 6 bytes shorter... "wow optimisation!" - one might say.

_But there is a problem that stems from this 'optimisation', rather laziness..._  
What if you wanted to print out a variable string?  

```c
  // format_string_vulnerability.c

  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <stdbool.h>

  int main(int argc, char** argv) { 
    char* correctPassword = "PASSWORD";
    bool passwordCorrect = false;

    char password[10 + 1];

  printf("%d", sizeof(password));
    fgets(password, 10, stdin);
    printf(password);
  }
```
## Reading the stack


## Writing data


%n -> write to item in the stack


http://www.cs.virginia.edu/~ww6r/CS4630/lectures/Format_String_Attack.pdf