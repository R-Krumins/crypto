#include <iostream>
#include <bitset>
#include "des-tables.h"

typedef unsigned long int word; //64 bit data type
typedef char byte; 

struct data {
	word L;
	word R;
	word key;
};

word permutate(word input, int* table, int inputSize, int outputSize) {
    word output = 0;
    for(int i = 0; i < outputSize; i++) {
        int m = table[i] - 1;
        output |= ((input >> (inputSize - 1 - m)) & 1) << (outputSize - 1 - i);
    }
    return output;
}

word bitShiftKey(word key, int round) {
	word key1 = (key >> 28) & 0xFFFFFFF;
	word key2 = key & 0xFFFFFFF;
	
	int n = shiftTable[round];
	key1 = ((key1 << n) | (key1 >> (28-n))) & 0xFFFFFFF;
	key2 = ((key2 << n) | (key2 >> (28-n))) & 0xFFFFFFF;

	key = (key1 << 28) | key2;
	return key;
}

word sBoxSubstitution(word R) {
	word newR = 0;
	for(int i = 0; i < 8; i++) {
		byte b = (byte)(R >> (42 - i*6)) & 0x3F;
		int row = (b & 0x20) >> 4 | (b & 0x1); 
		int col = (b & 0x1E) >> 1; 
		newR |= ((word)sBoxes[i][row * 16 + col]) << (28 - i*4); 
	}

	return newR;
}

data createData(word text, word key) {
	data d;
	text = permutate(text, initialPermTable, 64, 64);
	d.R = text & 0xFFFFFFFF;
	d.L = text >> 32;
	d.key = permutate(key, keyPermTable, 64, 56);

	return d;
}


void f(data& d, word* keys, int round, bool encrypt) {
 	if(round == 0) return;

	word tempL = d.L;
	d.L = d.R;

	int roundIndex = encrypt ? (16 - round) : (round - 1);

	d.R = permutate(d.R, expansionTable, 32, 48); 
	d.R = d.R ^ keys[roundIndex];
	d.R = sBoxSubstitution(d.R);
	d.R = permutate(d.R, pBox, 32, 32);
	d.R = d.R ^ tempL;
	
	round--;
	f(d, keys, round, encrypt);
}

word des(word text, word key, bool encrypt) {
	data d = createData(text, key);
   
	// genereate keys
	word keys[16];
	key = permutate(key, keyPermTable, 64, 56);
	for (int i = 0; i < 16; i++) {
		key = bitShiftKey(key, i);
		keys[i] = permutate(key, compresionTable, 56, 48);
	}
    
	f(d, keys, 16, encrypt);
    
	// Combine L and R parts to get the final result
	word result = ((word)d.R << 32) | d.L;
	result = permutate(result, finalPermTable, 64, 64);
	return result;
}

int main() {
	word plaintext = 0x0123456789ABCDEF;
	word key = 0x133457799BBCDFF1;


	std::cout << "PlainText: " << std::hex << plaintext << "\n";
	// Encrypt the plaintext
	word encrypted = des(plaintext, key, true);
	std::cout << "Encrypted: " << std::hex << encrypted << "\n";

	// Decrypt the ciphertext
	word decrypted = des(encrypted, key, false);
	std::cout << "Decrypted: " << std::hex << decrypted << "\n";
}

