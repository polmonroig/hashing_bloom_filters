#ifndef A_CUCKOO_HASHING_H
#define A_CUCKOO_HASHING_H

#include <vector>


#include "../../dictionary.h"
#include "../../../hash/hash_functions/hash_function.h"

/**
 * @class CuckooHashing
 * @brief CuckooHashing is a form of open addressing which uses
 * the cuckoo analogy in order to resolve collisions in hash
 * tables with worst-case constant lookup time.
 * */

class CuckooHashing : public Dictionary {

	public:

		/**
		 * @brief Default class constructor with hyper-parameters
		 * @param tableSize is the size of the hash table
		 * @param hash1 first hash definition
     	 * @param hash2 second hash definition
     	 * @param max maximum number of cockoo iterations
		 * */
		CuckooHashing(int tableSize, HashFunction &hash1, HashFunction &hash2, unsigned int max);

		/**
	     * @brief Function that inserts a value into the bloom filter
	     * @param value is the key to insert
	     * */
		virtual void insert(int value) final;

		/**
		 * @brief Function that finds if an item is in the hash table
		 * @param value to search
		 * @returns if found
		 * */
		virtual bool find(int value) final;

		/**
	     * @brief Function that gets how many probes where found in a given lookup
	     * @returns ithe number of probes
	     * */
		virtual unsigned int getCollisions() const;

		/**
		 * @brief Function that finds the theorical value of the avg probes of a hash table
		 * @param success is if it needs to return in case of success or fail
		 * @param loadFactor the loadFactor of the table
		 * @return the avg probes
		 * */
		virtual double getTheoricalValue(bool success, float loadFactor) const final;

	private:

		/**
		 * @brief returns a pair with the possible positions on the hash table
		 *        for a key given by the hash functions
		 * @param value is the key
		 * */
		std::pair<unsigned int, unsigned int> getPositions(int value) const;

		/**
		 * @brief hash table that stores keys
		 * */
		std::vector<int> hashTable;

		/**
		 * @brief executes the functionality of cuckoo hashing
		 * @param value is the key to insert or to change position
		 * @param pos is the position in which to insert the key
		 * @param i value that iterates until the maximum one
		 */
		void cuckoo(int value, unsigned int pos, unsigned int i);

		/**
	     * @brief two basic hash functions
	     * */
		HashFunction *h1, *h2;

		/**
		 * @brief maximum value for the cuckoo loop
		 * */
		unsigned int maxLoop;
};

#endif
