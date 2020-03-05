#include "separate_chaining_lists.h"


/** =================================
 *               PUBLIC
 *  =================================*/

SeparateChainingLists::SeparateChainingLists(int tableSize, HashFunction &hash) {

	m = tableSize;
	h = &hash;
	dictionary = std::vector<std::list<int> > (m);
}



void SeparateChainingLists::insert(int value) {

	unsigned int i = hash(value);

}

bool SeparateChainingLists::find(int value) const {

}

/** =================================
 *               PRIVATE
 *  =================================*/

unsigned int SeparateChainingLists::hash(int key) {

	return h->operator()(key, m);
}