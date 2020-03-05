#include "linear_probing.h"
#include <iostream>
using namespace std;

/** =================================
 *               PUBLIC
 *  =================================*/

LinearProbing::LinearProbing(int tableSize, HashFunction const &hash){
	m = tableSize;
	h = hash;
	i = 0;
	hashTable = std::vector<int>(m,-1);
}

bool LinearProbing::find(int value) {
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

void LinearProbing::insert(int value) {
	if (i < m) hashTable[getPosition(value)] = value;
	else cout << "The hash table is already full.";
}

/** =================================
 *               PRIVATE
 *  =================================*/

unsigned int LinearProbing::getPosition(int value) const {
	return (h(value,m) + i % m);
}


