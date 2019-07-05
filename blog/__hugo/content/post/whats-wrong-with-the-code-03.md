---
title: "What's Wrong With the Code - 03"
date: 2019-07-01T16:18:46+10:00

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


```c
unsigned short int f;
char mybuf[1024];

char* userstr = getuserstr();
f = strlen(userstr);

if (f > sizeof(mybuf)-5) die("string too long!");
strcpy(mybuf, userstr); 
```

# What&apos;s wrong with the code?

_strlen_.

A `short` is 2 bytes long, so 2^16 different values.  
An `unsigned short` has the range `0 - 65535`.

Perhaps it's good to take peek into [`string.c`](https://github.com/torvalds/linux/blob/6fbc7275c7a9ba97877050335f290341a1fd8dbf/lib/string.c#L512-L519) to see how [`strlen`](https://github.com/torvalds/linux/blob/6fbc7275c7a9ba97877050335f290341a1fd8dbf/lib/string.c#L512-L519) works.
```c
/**
 * strlen - Find the length of a string
 * @s: The string to be sized
 */
size_t strlen(const char *s)
{
	const char *sc;

	for (sc = s; *sc != '\0'; ++sc)
		/* nothing */;
	return sc - s;
}
```

We create a `char` pointer `sc`, set to `s`, and increase `sc` until it contains a null terminator/byte.  
Then, we return the difference between the final and starting address as an `unsigned int` (32-bit), or an `unsigned long long` (64-bit)

Let's consider the 32-bit variant, an `unsigned int`.  
An `int` is 4 bytes long, 2^32 different values.  
So for an `unsigned int`, it has the range `0 - 4294967295`

What happens when you compare an `unsigned short` with an `unsigned int`?  
Well if you've read the [first "What's Wrong With the Code"](../whats-wrong-with-the-code-01) post - **type coercions** are nightmares.

So back into the code, storing a `size_t` type value (4 bytes on a 32-bit machine) into a `short` type variable (2 bytes on a 32-bit machine) will cause **truncation issues**.
Storing a number greater than `65535` into an `unsigned short` will cause that number to be wrapped (sort of like `n % 65536`).  

So if we were to try store `66666` (_i.e `unsigned short v = 66666`_), we would actually see `v = 1131`

So in application of this problematic code, if the length of `userstr` were to be greater than `65535`, the number would be wrapped to a small number, and therefore the program termination will not happen.  
Inbound buffer overflow.
