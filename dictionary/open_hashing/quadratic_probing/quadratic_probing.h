#ifndef A_QUADRATIC_PROBING_H
#define A_QUADRATIC_PROBING_H

#include <vector>

#include "../../dictionary.h"
#include "../../../hash/hash_functions/hash_function.h"

class QuadraticProbing : public Dictionary {

	public: 

		QuadraticProbing(int tableSize, HashFunction &hash);

		virtual void insert(int value) final;

		virtual bool find(int value) final;

	private:

		unsigned int getPosition(int value, unsigned int i) const;
		std::vector<int> hashTable;

		HashFunction *h;
		static constexpr float c = 0.5f;

};

#endif