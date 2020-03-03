#ifndef A_OPEN_HASHING_H
#define A_OPEN_HASHING_H

#include <vector>

#include "../dictionary.h"
#include "../../hash/hash_functions/division_hash.h"

class OpenHashing : public Dictionary{

public: 

	OpenHashing(int tableSize, HashFunction const &hash);

	void insert(int value) final;

	bool find(int value) final;

	std::vector<int> hashTable;
private:

	HashFunction h;

	unsigned int linearProbing(int value) const;
	
	unsigned int i;

};

#endif