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
	key1 = (key1 << n) | (key1 >> (28-n));
	key2 = (key2 << n) | (key2 >> (28-n));
	
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


void f(data& d, int round) {
 	if(round == 0) return;
	
	word tempL = d.L;
	d.L = d.R;

	d.key = bitShiftKey(d.key, (16 - round));
	d.R = permutate(d.R, expansionTable, 32, 48); 
	word compressedKey = permutate(d.key, compresionTable, 56, 48);
	d.R = d.R ^ compressedKey;
	d.R = sBoxSubstitution(d.R);
	d.R = permutate(d.R, pBox, 32, 32);
	d.R = d.R ^ tempL;

	round--;
	f(d, round);
}


int main() {

	/* word text = 0x0123456789ABCDEF;
	word key  = 0x133457799BBCDFF1;

	data d = createData(text, key);
	f(d, 16);

	std::cout << std::bitset<32>(d.L) << "\n";
	std::cout << std::bitset<32>(d.R) << "\n";

	word encrypted = ((word)d.R << 32) | d.L;
	encrypted = permutate(encrypted, finalPermTable, 64, 64);
	
	std::cout << std::hex << encrypted << "\n"; */

	word x, y;
	// expansion perm
	x = 0xF0AAF0AA;
	y = permutate(x, expansionTable, 32, 48);
	std::cout << std::hex << y << "\n";
	std::cout << (0x7A15557A1555 == y) << "\n\n";
	// compression perm
	x = 0xE19955FAACCF1E;
	y = permutate(x, compresionTable, 56, 48);
	std::cout << std::hex << y << "\n";
	std::cout << (0x1B02EFFC7072 == y) << "\n\n";
	// pbox perm
	x = 0x5C82B597;
	y = permutate(x, pBox, 32, 32);
	std::cout << std::hex << y << "\n";
	std::cout << (0x234AA9BB == y) << "\n\n";
	// sbox substition
	x = 0x6117BA866527;
	y = sBoxSubstitution(x);
	std::cout << std::hex << y << "\n";
	std::cout << (0x5C82B597 == y) << "\n\n";
}
