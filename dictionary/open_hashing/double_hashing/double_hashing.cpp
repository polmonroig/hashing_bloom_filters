#include "double_hashing.h"
#include <iostream>
using namespace std;

/* =================================
 *               PUBLIC
 *  =================================*/

DoubleHashing::DoubleHashing(int tableSize, HashFunction &hash1, HashFunction &hash2) {
	m = tableSize;
	h1 = &hash1;
	h2 = &hash2;
	i = 0;
	hashTable = vector<int>(m,-1);
}

bool DoubleHashing::find(int value) {
	i = 0;
	while(i < m) {
		unsigned int key = getPosition(value);
		if (hashTable[key] != -1) {
			if (hashTable[key] != value) ++i;
			else return true;
		}
		else return false;
	}
	return false;
}

void DoubleHashing::insert(int value) {
	if (i < m) hashTable[getPosition(value)] = value;
	else cerr << "The hash table is already full.";
}

/* =================================
 *               PRIVATE
 *  =================================*/

unsigned int DoubleHashing::getPosition(int value) const {
	return (((*h1)(value,m) + i*(*h2)(value,m)) % m);
}