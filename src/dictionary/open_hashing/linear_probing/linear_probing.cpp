#include "linear_probing.h"
#include <iostream>
using namespace std;

/*  =================================
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
		unsigned int pos = hashTable[key];
		if (pos != -1) {
			if (pos != value) ++i;
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
	collisions = i + 1;
	if (!finish) cerr << "The hash table is already full." << endl;
}


unsigned int LinearProbing::getCollisions() const {
	return collisions;
}

double LinearProbing::getTheoricalValue(bool success, float loadFactor) const{
	  float factor = (1.0 - loadFactor);
		if(success){
				return 0.5 * (1.0 + (1.0 / factor));
		}
		else{
			return 0.5 * (1.0 + (1.0 / (factor * factor)));
		}
}


/*  =================================
 *               PRIVATE
 *  =================================*/

unsigned int LinearProbing::getPosition(int value, unsigned int i) const {
	return (((*h)(value,m) + i) % m);
}
