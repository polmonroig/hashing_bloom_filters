#ifndef A_DOUBLE_HASHING_H
#define A_DOUBLE_HASHING_H

#include <vector>

#include "../../dictionary.h"
#include "../../../hash/hash_functions/hash_function.h"

class DoubleHashing : public Dictionary {

	public: 

		DoubleHashing(int tableSize, HashFunction &hash1, HashFunction &hash2);

		virtual void insert(int value) final;

		virtual bool find(int value) final;

		unsigned int getPosition(int value) const;
		std::vector<int> hashTable;
	private:


		HashFunction *h1, *h2;
		unsigned int i;

};

#endif