#ifndef A_LINEAR_PROBING_H
#define A_LINEAR_PROBING_H

#include <vector>

#include "../../dictionary.h"
#include "../../../hash/hash_functions/hash_function.h"

class LinearProbing : public Dictionary{

public: 

	LinearProbing(int tableSize, HashFunction &hash);

	virtual void insert(int value) final;

	virtual bool find(int value) final;

private:

	unsigned int getPosition(int value) const;
	std::vector<int> hashTable;

	HashFunction *h;
	unsigned int i;

};

#endif