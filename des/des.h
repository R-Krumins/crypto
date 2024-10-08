#include "utility.h"
#include <vector>

namespace DES {
	std::vector<word> encrypt(const char* plaintext, word key);
	std::string decrypt(std::vector<word> encryptedChunks, word key);
}
