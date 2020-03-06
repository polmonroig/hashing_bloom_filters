#include "linear_probing.h"
#include <iostream>
using namespace std;

/* =================================
 *               PUBLIC
 *  =================================*/

LinearProbing::LinearProbing(int tableSize, HashFunction &hash){
	m = tableSize;
	h = &hash;
	hashTable = vector<int>(m,-1);
}

bool LinearProbing::find(int value) {
	unsigned int i = 0;
	while(i < m) {
		unsigned int key = getPosition(value, i);
		if (hashTable[key] != -1) {
			if (hashTable[key] != value) ++i;
			else return true;
		}
		else return false;
	}
	return false;
}

void LinearProbing::insert(int value) {
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
	colisions = i;
	if (!finish) cerr << "The hash table is already full." << endl;
}


unsigned int LinearProbing::getColisions() const {
	return colisions;
}
/* =================================
 *               PRIVATE
 *  =================================*/

unsigned int LinearProbing::getPosition(int value, unsigned int i) const {
	return (((*h)(value,m) + i) % m);
}


