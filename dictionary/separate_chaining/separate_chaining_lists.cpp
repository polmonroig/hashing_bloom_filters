#include "separate_chaining_lists.h"


/* =================================
 *               PUBLIC
 *  =================================*/

SeparateChainingLists::SeparateChainingLists(int tableSize, HashFunction &hash) {

	m = tableSize;
	h = &hash;
	dictionary = std::vector<std::list<int> > (m);
}

void SeparateChainingLists::insert(int value) {

	unsigned int i = hash(value);

	dictionary[i].push_back(value);
}

bool SeparateChainingLists::find(int value) {

	unsigned int i = hash(value);

	for (std::list<int>::iterator it = dictionary[i].begin(); it != dictionary[i].end(); ++it)
		if (*it == value) {
			dictionary[i].erase(it);
			dictionary[i].push_front(value);
			return true;
		}

	return false;
}

unsigned int SeparateChainingLists::getCollisions() const {
	return colisions;
}

/* =================================
 *               PRIVATE
 *  =================================*/

unsigned int SeparateChainingLists::hash(int key) const {

	return h->operator()(key, m);
}
