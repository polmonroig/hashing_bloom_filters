#include "separate_chaining_vector.h"


/** =================================
 *               PUBLIC
 *  =================================*/

SeparateChainingVector::SeparateChainingVector(int tableSize, HashFunction &hash) {

	m = tableSize;
	h = &hash;
	dictionary = std::vector<std::vector<int> > (m);
}

void SeparateChainingVector::insert(int value) {

	unsigned int i = hash(value);

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

/** =================================
 *               PRIVATE
 *  =================================*/

unsigned int SeparateChainingVector::hash(int key) const {

	return h->operator()(key, m);
}
