#include "quadratic_probing.h"
#include <iostream>
using namespace std;

/*  =================================
 *               PUBLIC
 *  =================================*/


QuadraticProbing::QuadraticProbing(int tableSize, HashFunction &hash) {
	m = tableSize;
	h = &hash;
	hashTable = vector<int>(m,-1);
}

bool QuadraticProbing::find(int value) {
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

void QuadraticProbing::insert(int value) {
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


unsigned int QuadraticProbing::getCollisions() const {
	return collisions;
}

/*  =================================
 *               PRIVATE
 *  =================================*/

unsigned int QuadraticProbing::getPosition(int value, unsigned int i) const {
	return (int((*h)(value,m) + c*i + c*i*i) % m);
}