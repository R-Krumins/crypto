#include "args.h"
#include <cstring>
#include <iostream>

namespace Args {
	const char* plaintext;
	word key;


	int panic(const char* msg) {
		std::cout << msg << std::endl;
		return 1;
	}

	// return true for success
	bool parseToHex(word* key, const char* txt, int expectedLength) {
		if(std::strlen(txt) != expectedLength) return false;	
		char* endChar;
	    *key = std::strtoull(txt, &endChar, 16);
		if(*endChar != 0) return false; // did not parse till the end of txt
		return true;
	}

	int parse(int argc, char* argv[]) {
		if(argc != 3) return panic("Invalid argument count:\nRequired:<plain text> <key>");
		plaintext = argv[1];
		
		bool success = parseToHex(&key, argv[2], 16);
		if(!success) return panic("Invalid key: could not parse as hexidecimal number");
		return 0;
	}


}
