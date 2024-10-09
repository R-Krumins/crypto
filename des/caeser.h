#pragma once

#include <cstring>
#include <iostream>

namespace Caeser {
	void encrypt(char* encrypted, const char* plaintext, int key);
	void decrypt(char* decrypted, const char* encrypted, int key);	
}
