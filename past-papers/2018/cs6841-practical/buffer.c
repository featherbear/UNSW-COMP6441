#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
COMP6841 2018s1 technical component

buffer.c - intentionally vulnerable binary.
The binary `buffer` is compiled with the correct win function which will give you the flag..

Compiled with `gcc -m32 -o buffer -std="c99" buffer.c`
*/

void win(){
	char *key = "7f61b7ea61f3f5ee1e493473b14db2963e29a046c0175db4763ca3ee688e87f9703d5f38ab601f2d07eb096cc950bd35a9fa90bf58f0052cf0f47a2c7ab6035d";
	char enc_flag[49];
	enc_flag[0] = 0x74;
	enc_flag[1] = 0x29;
	enc_flag[2] = 0x7b;
	enc_flag[3] = 0x61;
	enc_flag[4] = 0x54;
	enc_flag[5] = 0x0f;
	enc_flag[6] = 0x51;
	enc_flag[7] = 0x50;
	enc_flag[8] = 0x4d;
	enc_flag[9] = 0x68;
	enc_flag[10] = 0x09;
	enc_flag[11] = 0x46;
	enc_flag[12] = 0x46;
	enc_flag[13] = 0x46;
	enc_flag[14] = 0x08;
	enc_flag[15] = 0x04;
	enc_flag[16] = 0x42;
	enc_flag[17] = 0x0d;
	enc_flag[18] = 0x51;
	enc_flag[19] = 0x5d;
	enc_flag[20] = 0x13;
	enc_flag[21] = 0x40;
	enc_flag[22] = 0x5f;
	enc_flag[23] = 0x5a;
	enc_flag[24] = 0x11;
	enc_flag[25] = 0x11;
	enc_flag[26] = 0x5b;
	enc_flag[27] = 0x0a;
	enc_flag[28] = 0x07;
	enc_flag[29] = 0x13;
	enc_flag[30] = 0x19;
	enc_flag[31] = 0x6f;
	enc_flag[32] = 0x5c;
	enc_flag[33] = 0x10;
	enc_flag[34] = 0x15;
	enc_flag[35] = 0x4b;
	enc_flag[36] = 0x04;
	enc_flag[37] = 0x10;
	enc_flag[38] = 0x55;
	enc_flag[39] = 0x41;
	enc_flag[40] = 0x06;
	enc_flag[41] = 0x43;
	enc_flag[42] = 0x5e;
	enc_flag[43] = 0x5a;
	enc_flag[44] = 0x50;
	enc_flag[45] = 0x45;
	enc_flag[46] = 0x1f;
	enc_flag[47] = 0x34;
	enc_flag[48] = 0x00;

	char flag[49];
	int i;
	for (i = 0; i < 49; i++ ) {
		flag[i] = enc_flag[i] ^ key[i];
	}
	flag[48] = 0;

	printf("FLAG: %s\n", flag);
}



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
		win();
	} else {
		printf("woop was not overwritten correctly..\n");
		printf("Try again... :)\n");
	}

	return EXIT_SUCCESS;
}