#include <gtest/gtest.h>
#include "des.cpp"
#include "des-tables.h"

TEST(DES, functions) {
	word x, y;
	// expansion perm
	x = 0xF0AAF0AA;
	y = permutate(x, expansionTable, 32, 48);
	EXPECT_EQ(0x7A15557A1555, y);

	// compression perm
	x = 0xE19955FAACCF1E;
	y = permutate(x, compresionTable, 56, 48);
	EXPECT_EQ(0x1B02EFFC7072 , y);

	// pbox perm
	x = 0x5C82B597;
	y = permutate(x, pBox, 32, 32);
	EXPECT_EQ(0x234AA9BB , y);

	// sbox substition
	x = 0x6117BA866527;
	y = sBoxSubstitution(x);
	EXPECT_EQ(0x5C82B597 , y);
}
