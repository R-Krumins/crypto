#pragma once

#include "utility.h"
#include <cstdlib>  

namespace Args {
	enum class Algo {NONE, CAESER , DES};
	extern Algo selectedAlgo;
	extern const char* plaintext;
	extern word key;
	extern int intKey;

	// return status code
	// 0 - success in parsing arguments
	// 1 - failure	
	void parse(int argc, char* argv[]);
}

