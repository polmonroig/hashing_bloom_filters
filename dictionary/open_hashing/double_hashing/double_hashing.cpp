#include "double_hashing.h"
#include <iostream>
using namespace std;

/*  =================================
 *               PUBLIC
 *  =================================*/

DoubleHashing::DoubleHashing(int tableSize, HashFunction &hash1, HashFunction &hash2) {
	m = tableSize;
	h1 = &hash1;
	h2 = &hash2;
	hashTable = vector<int>(m,-1);
}

bool DoubleHashing::find(int value) {
	unsigned int i = 0;
	while(i < m) {
		unsigned int key = getPosition(value, i);
		unsigned int pos = hashTable[key];
		if (pos != -1) {
			if (pos != value) ++i;
			else return true;
		}
		else return false;
	}
	return false;
}

void DoubleHashing::insert(int value) {
	unsigned int i = 0;
	bool finish = false;
	while(!finish and i < m) {
		unsigned int key = getPosition(value, i);
		if (hashTable[key] != -1) ++i;
		else {
			finish = true;
			hashTable[key] = value;
		}
	}
	collisions = i;
	if (!finish) cerr << "The hash table is already full." << endl;
}


unsigned int DoubleHashing::getCollisions() const {
	return collisions;
}

double DoubleHashing::getTheoricalValue(bool success, float loadFactor) const{
		return 0;
}


/*  =================================
 *               PRIVATE
 *  =================================*/

unsigned int DoubleHashing::getPosition(int value, unsigned int i) const {
	return (((*h1)(value,m) + i*(*h2)(value,m)) % m);
}
