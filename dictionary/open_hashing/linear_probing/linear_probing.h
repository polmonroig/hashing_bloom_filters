#ifndef A_LINEAR_PROBING_H
#define A_LINEAR_PROBING_H

#include <vector>

#include "../../dictionary.h"
#include "../../../hash/hash_functions/hash_function.h"


/**
 * @class LinearProbing
 * @brief LinearProbing is a form of open addressing which uses 
 * 		  a start index and a stepping value in order to resolve 
 * 		  collisions in hash tables.
 * */

class LinearProbing : public Dictionary{

public: 

	/**
	 * @brief Default class constructor with hyper-parameters
	 * @param tableSize is the size of the hash table
	 * @param hash definition
	 * */
	LinearProbing(int tableSize, HashFunction &hash);

	/**
	 * @brief Function that inserts a value into the hash table
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
	 * @brief Function that returns the number of colisions on the hash table 
	 * */
    virtual unsigned int getCollisions() const;


private:

	/**
	 * @brief returns the position on the hash table for a key utilizing linear probing
	 * @param value is the key
	 * @param i is the stepping value
	 * */
	unsigned int getPosition(int value, unsigned int i) const;

	/**
	 * @brief hash table that stores keys
	 * */
	std::vector<int> hashTable;

	/**
	 * @brief basic hash function
	 */
	HashFunction *h;

};

#endif