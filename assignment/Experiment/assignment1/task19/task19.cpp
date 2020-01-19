#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <openssl/evp.h>
using namespace std;
#define llong long long
#define KEYSIZE 16
#define TEXTSIZE 17
int main(){
	llong start = 1524013689L, end = 1524020889L;
	char plaintext[TEXTSIZE] = "255044462d312e350a25d0d4c5d80a34",
         ciphertext[TEXTSIZE] = "d06bf9d0dab8e8ef880660d2af65aa82",
         iv[TEXTSIZE] = "09080706050403020100A2B2C2D2E2F2";
    for(int i = start; i <= end; i++){
		srand(i);
		char key[KEYSIZE];
        for (j = 0; j< KEYSIZE; j++){
            key[j] = rand()%256;
        }
        
	}
	return 0;
}
