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
    if(value == 1194989329)std::cout << "Seg fault value!" << std::endl;
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

    unsigned int k = hashTable[pos];
    hashTable[pos] = value;
    while(i < maxLoop && k != -1){ // while not empty pos && not loop found
        pair<unsigned int, unsigned int> keys = getPositions(k);
        if (keys.first == pos) pos = keys.second;
        else pos = keys.first;
        value = k;
        ++i;
        unsigned int k = hashTable[pos];
        hashTable[pos] = value;
    }
	collisions = i;
}

pair<unsigned int, unsigned int> CuckooHashing::getPositions(int value) const {
	unsigned int p1 = (*h1)(value,m);
	unsigned int p2 = (*h2)(value,m);
	return make_pair(p1,p2);
}
