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

void win(){
	char *key = "04fa1afd8328e787a3f4c0237af028ce8f2c305eee7691819008a0915fa2cc2bb99e6e03f24f1ea56868be05143046dd036ab48c4c9bc20a97cc6355170f31ad";
	char enc_flag[35];
	enc_flag[0] = 0x73;
	enc_flag[1] = 0x7b;
	enc_flag[2] = 0x2b;
	enc_flag[3] = 0x31;
	enc_flag[4] = 0x07;
	enc_flag[5] = 0x59;
	enc_flag[6] = 0x52;
	enc_flag[7] = 0x55;
	enc_flag[8] = 0x43;
	enc_flag[9] = 0x55;
	enc_flag[10] = 0x02;
	enc_flag[11] = 0x4a;
	enc_flag[12] = 0x08;
	enc_flag[13] = 0x03;
	enc_flag[14] = 0x4c;
	enc_flag[15] = 0x44;
	enc_flag[16] = 0x15;
	enc_flag[17] = 0x41;
	enc_flag[18] = 0x57;
	enc_flag[19] = 0x5a;
	enc_flag[20] = 0x04;
	enc_flag[21] = 0x43;
	enc_flag[22] = 0x12;
	enc_flag[23] = 0x07;
	enc_flag[24] = 0x45;
	enc_flag[25] = 0x52;
	enc_flag[26] = 0x46;
	enc_flag[27] = 0x52;
	enc_flag[28] = 0x06;
	enc_flag[29] = 0x5c;
	enc_flag[30] = 0x1e;
	enc_flag[31] = 0x65;
	enc_flag[32] = 0x20;
	enc_flag[33] = 0x0a;
	enc_flag[34] = 0x00;

	char flag[35];
	int i;
	for (i = 0; i < 35; i++ ) {
		flag[i] = enc_flag[i] ^ key[i];
	}
	flag[34] = 0;

	printf("FLAG: %s\n", flag);
}


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
		win();
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
