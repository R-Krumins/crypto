#pragma once

#include "utility.h"
#include <cstdlib>  

namespace Args {
	extern const char* plaintext;
	extern word key;

	// return status code
	// 0 - success in parsing arguments
	// 1 - failure	
	int parse(int argc, char* argv[]);
}

