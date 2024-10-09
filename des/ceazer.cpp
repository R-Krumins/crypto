#include <cstring>
#include <iostream>
//namespace Ceazer {

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
	
	int main() {
		
		const char* plaintext = "we attack at dawn zzz";
		int key = 5;

		int size = strlen(plaintext)+1;
		char encrypted[size];
		char decrypted[size];
		
		encrypt(encrypted, plaintext, key);
		decrypt(decrypted, encrypted, key);

		std::cout << "PlainText: " << plaintext << "\n";
		std::cout << "Encrypted: " << encrypted << "\n";
		std::cout << "Decrypted: " << decrypted << "\n";

		return 0;
	}
//}
