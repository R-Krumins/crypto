#include "des.h"
#include "utility.h"
#include <iostream>
#include <ostream>
#include <vector>
#include "args.h"

int main(int argc, char* argv[]) {

	//char plainText[] = "My very secret message";
	//word key =  0x133457799BBCDFF1;
	
	int status = Args::parse(argc, argv);	
	if(status == 1) return 1;

	std::vector<word> encrypted = DES::encrypt(Args::plaintext, Args::key);
	std::string decrypted = DES::decrypt(encrypted, Args::key);

	std::cout << "PlainText: " << Args::plaintext << std::endl;
	printEncryptedChunks(encrypted);
	std::cout << "Decrypted: " << decrypted << std::endl;

	return 0;
}
