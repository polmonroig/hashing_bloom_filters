#ifndef A_LINEAR_PROBING_H
#define A_LINEAR_PROBING_H

#include <vector>

#include "../../dictionary.h"
#include "../../../hash/hash_functions/division_hash.h"

class LinearProbing : public Dictionary{

public: 

	LinearProbing(int tableSize, HashFunction const &hash);

	virtual void insert(int value) final;

	virtual bool find(int value) final;

	std::vector<int> hashTable;
	unsigned int getPosition(int value) const;
private:

	HashFunction h;

	
	unsigned int i;

};

#endif