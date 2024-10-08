#include "des.h"
#include "utility.h"
#include <iostream>
#include <vector>

int main() {

	char plainText[] = "My very secret message";
	word key =  0x133457799BBCDFF1;

	std::vector<word> encrypted = DES::encrypt(plainText, key);
	std::string decrypted = DES::decrypt(encrypted, key);

	std::cout << "PlainText: " << plainText << std::endl;
	printEncryptedChunks(encrypted);
	std::cout << "Decrypted: " << decrypted << std::endl;

	/* word plaintext = 0x0123456789ABCDEF;
	word key =  0x133457799BBCDFF1;
	word key2 = 0x563452299BBADFF1;


	std::cout << "PlainText: " << std::hex << plaintext << "\n";
	// Encrypt the plaintext
	word encrypted = des(plaintext, key, true);
	std::cout << "Encrypted: " << std::hex << encrypted << "\n";

	// Decrypt the ciphertext
	word decrypted = des(encrypted, key, false);
	std::cout << "Decrypted: " << std::hex << decrypted << "\n"; */
}
