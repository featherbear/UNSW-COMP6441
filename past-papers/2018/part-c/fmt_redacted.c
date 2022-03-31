#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

/*
COMP6841 2018s1 technical component

fmt.c - intentionally vulnerable binary.
The binary `fmt` is compiled with the correct win function which will give you the flag..

Compiled with `gcc -m32 -o fmt -std="c99" fmt.c`
*/

void secure_auth(char *format_string) {
	printf("For the 6841 examination, we have written a super duper secure authentication application\n");
	printf("Perhaps you could find our super secure key on the stack?\n");
	
	// The strongest key generation in the cyberz
	srand(time(NULL));
	volatile int pin = rand() % 100; // random number mod 100
	
	int user_pin;

	// Format string :o
	printf(format_string);

	printf("\nPlease enter the randomly generated pin correctly:\n");
	scanf("%d", &user_pin);
	if (user_pin == pin) {
		// You want to get here - code block redacted in the source code
	} else {
		printf("Wrong pin code.. Try again..\n");
	}
}

int main(int argc, char * argv[]) {
	if (argc < 2) {
		printf("Usage: %s format_string\n", argv[0]);
		return EXIT_FAILURE;
	}

	secure_auth(argv[1]);
	return EXIT_SUCCESS;
}
