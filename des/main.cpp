#include "des.h"
#include "utility.h"
#include <iostream>
#include <ostream>
#include <vector>
#include "args.h"
#include "caeser.h"

int main(int argc, char* argv[]) {

	//char plainText[] = "My very secret message";
	//word key =  0x133457799BBCDFF1;
	
	try {
		Args::parse(argc, argv);
	}	
	catch (const char* e) {
		std::cout << e << std::endl;
		return 1;
	}

	int size = std::strlen(Args::plaintext);
	char* encrypted = new char[size];
	char* decrypted = new char[size];

	switch(Args::selectedAlgo) {
	case Args::Algo::CAESER:
		Caeser::encrypt(encrypted, Args::plaintext, Args::intKey);
		Caeser::decrypt(decrypted, encrypted, Args::intKey);
		break;
	case Args::Algo::DES:
		break;
	}
	

	std::cout << "PlainText: " << Args::plaintext << std::endl;
	std::cout << "Encrypted: " << encrypted << std::endl;
	std::cout << "Decrypted: " << decrypted << std::endl;

	delete[] encrypted;
	delete[] decrypted;
	/* std::vector<word> encrypted = DES::encrypt(Args::plaintext, Args::key);
	std::string decrypted = DES::decrypt(encrypted, Args::key);*/


	return 0;
}
