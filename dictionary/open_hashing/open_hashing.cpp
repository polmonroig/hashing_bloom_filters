#include "open_hashing.h"
#include <iostream>
using namespace std;

/** =================================
 *               PUBLIC
 *  =================================*/

OpenHashing::OpenHashing(int tableSize, HashFunction const &hash){
	m = tableSize;
	h = hash;
	i = 0;
	hashTable = std::vector<int>(m,-1);
}

bool OpenHashing::find(int value) {

	while(i < m) {
		unsigned int key = linearProbing(value);
		if (hashTable[key] != -1) {
			if (hashTable[key] != value) ++i;
			else return true;
		}
		else return false;
	}
	return false;
}

void OpenHashing::insert(int value) {
	if (i < m) hashTable[linearProbing(value)] = value;
	else cout << "The hash table is already full.";
}

/** =================================
 *               PRIVATE
 *  =================================*/

unsigned int OpenHashing::linearProbing(int value) const {
	return (h(value,m) + i % m);
}


