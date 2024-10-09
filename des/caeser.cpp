#include "caeser.h"

namespace Caeser {

	void encrypt(char* encrypted, const char* plaintext, int key) {
		int i = 0;
		while(plaintext[i] != 0) {
			char c = plaintext[i];
			if(c >= 'A' && c <= 'Z')
				encrypted[i] = (c - 'A' + key + 26) % 26 + 'A';
			else if(c >= 'a' && c <= 'z')
				encrypted[i] = (c - 'a' + key + 26) % 26 + 'a';
			else
				encrypted[i] = c;
			i++;
		}
		encrypted[i] = 0;
	}

	void decrypt(char* decrypted, const char* encrypted, int key) {
		encrypt(decrypted, encrypted, -key);
	}
}
