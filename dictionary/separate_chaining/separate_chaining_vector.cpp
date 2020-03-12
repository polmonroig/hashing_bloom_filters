#include "separate_chaining_vector.h"


/* =================================
 *               PUBLIC
 *  =================================*/

SeparateChainingVector::SeparateChainingVector(int tableSize, HashFunction &hash) {

	m = tableSize;
	h = &hash;
	dictionary = std::vector<std::vector<int> > (m);
	collisions = 0;
}

void SeparateChainingVector::insert(int value) {

	unsigned int i = hash(value);

	if (dictionary[i].size() > 0) ++collisions;

	dictionary[i].push_back(value);
}

bool SeparateChainingVector::find(int value) {

	unsigned int i = hash(value);

	for (std::vector<int>::iterator it = dictionary[i].begin(); it != dictionary[i].end(); ++it)
		if (*it == value) {
			dictionary[i].erase(it);
			dictionary[i].insert(dictionary[i].begin(), value);
			return true;
		}

	return false;
}

unsigned int SeparateChainingVector::getCollisions() const {
	return collisions;
}

double SeparateChainingVector::getTheoricalValue(bool success, float loadFactor) const{
		if(success){
				return 1 + ((loadFactor * loadFactor) / 2);
		}
		else{
				return 1 + (loadFactor / 2);
		}
}


/* =================================
 *               PRIVATE
 *  =================================*/

unsigned int SeparateChainingVector::hash(int key) const {

	return h->operator()(key, m);
}
