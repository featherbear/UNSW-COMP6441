#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
COMP6841 2018s1 technical component

buffer.c - intentionally vulnerable binary - redacted version
Compiled with `gcc -m32 -o buffer -std="c99" buffer.c`
*/

int main(int argc, char * argv[]) {
	printf("Welcome to the 6841 buffer overflow exam question 2018s1 (tm)\n\n");
	
	// How would this look on the stack? - Smash it!
	volatile int a = 1;
	volatile int woop = 2;
	volatile int b = 3;
	volatile int c = 4;
	char buf[32];

	printf("Give us a buffer:\n");

	gets(&buf);

	if (woop == 0x65203272) {
		// This looks interesting :o
		// You want to get here - code block redacted in the source code
	} else {
		printf("woop was not overwritten correctly..\n");
		printf("Try again... :)\n");
	}

	return EXIT_SUCCESS;
}