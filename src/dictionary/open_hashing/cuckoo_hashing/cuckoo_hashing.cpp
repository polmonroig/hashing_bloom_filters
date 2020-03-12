#include "cuckoo_hashing.h"
#include <iostream>
using namespace std;

/*  =================================
 *               PUBLIC
 *  =================================*/

 CuckooHashing::CuckooHashing(int tableSize, HashFunction &hash1, HashFunction &hash2, unsigned int max){
 	m = tableSize;
 	h1 = &hash1;
	h2 = &hash2;
 	hashTable = vector<int>(m,-1);
 	maxLoop = max;
 }

 bool CuckooHashing::find(int value) {
 	pair<unsigned int, unsigned int> keys = getPositions(value);
 	if (hashTable[keys.first] == value or hashTable[keys.second] == value) return true;
 	return false;
 }

 void CuckooHashing::insert(int value) {
 	pair<unsigned int, unsigned int> keys = getPositions(value);
 	cuckoo(value, keys.first, 0);
 }

 unsigned int CuckooHashing::getCollisions() const {
 	return collisions;
 }


 double CuckooHashing::getTheoricalValue(bool success, float loadFactor) const{
     return 0;
 }

/*  =================================
 *               PRIVATE
 *  =================================*/

void CuckooHashing::cuckoo(int value, unsigned int pos,unsigned int i) {

	if (i < maxLoop) {
		unsigned int k = hashTable[pos];
        if(k != value) {
			hashTable[pos] = value;
			if (k != -1) {
				pair<unsigned int, unsigned int> keys = getPositions(k);
				if (keys.first == pos) cuckoo(k, keys.second,++i);
				else cuckoo(k, keys.first, ++i);
			}
		}
	}
	else cerr << "Key " << value << " not positioned, possible presence of a cycle." << endl;
	collisions = i;
}

pair<unsigned int, unsigned int> CuckooHashing::getPositions(int value) const {
	unsigned int p1 = (*h1)(value,m);
	unsigned int p2 = (*h2)(value,m);
	return make_pair(p1,p2);
}
