#include "args.h"
#include <cstring>
#include <exception>
#include <iostream>
#include <map>
#include <ostream>

namespace Args {
std::map<std::string, Algo> algoMap = {
	{"caeser", Algo::CAESER},
	{"des", Algo::DES}
};
Algo selectedAlgo;

const char* plaintext;
word key;
int intKey;

bool parseToHex(word* key, const char* txt, int expectedLength) {
	if(std::strlen(txt) != expectedLength) return false;	
	char* endChar;
	*key = std::strtoull(txt, &endChar, 16);
	if(*endChar != 0) return false; // did not parse till the end of txt
	return true;
}


void parse(int argc, char* argv[]) {
	if(argc != 4) throw "Invalid argument count:\nRequired: <algorithm> <plain text> <key>";

	std::string argAlgo = argv[1];
	std::string argPlaintext = argv[2];
	std::string argKey = argv[3];

	selectedAlgo = algoMap[argAlgo];
	std::cout << argAlgo << "\n";
	std::cout << (selectedAlgo == Algo::NONE) << "\n";
	std::cout << (argAlgo == "caeser") << "\n";
	if(selectedAlgo == Algo::NONE) throw "Invalid <algorithm> argument";

	switch(selectedAlgo) {
	case Algo::CAESER:
		try {intKey = std::stoi(argKey);}
		catch(...) {throw "Ceazer key must be a integer!";}
		plaintext = argPlaintext.c_str();
		break;
	case Algo::DES:
		break;
	}
}
}
