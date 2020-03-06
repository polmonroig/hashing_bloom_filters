#include "quadratic_probing.h"
#include <iostream>
using namespace std;

/* =================================
 *               PUBLIC
 *  =================================*/


QuadraticProbing::QuadraticProbing(int tableSize, HashFunction &hash) {
	m = tableSize;
	h = &hash;
	i = 0;
	hashTable = vector<int>(m,-1);
}

bool QuadraticProbing::find(int value) {
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

void QuadraticProbing::insert(int value) {
	if (i < m) hashTable[getPosition(value)] = value;
	else cerr << "The hash table is already full.";
}

/* =================================
 *               PRIVATE
 *  =================================*/

unsigned int QuadraticProbing::getPosition(int value) const {
	return (int((*h)(value,m) + c*i + c*i*i) % m);
}