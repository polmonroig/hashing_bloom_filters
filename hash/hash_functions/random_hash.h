#ifndef A_RANDOM_HASH_H
#define A_RANDOM_HASH_H


#include "hash_function.h"
#include "../../random/rand_generator.h"

class RandomHash : public HashFunction{

public:


    /**
     * @brief hash division operator
     * @pre tableSize > 0
     * @post true
     * @param value is the key to be hashed
     * @param tableSize is the size of the hash table
     * @returns the hashed value of the key
     * */
    virtual unsigned int operator()(int key, unsigned int tableSize) const final ;

};


#endif //A_RANDOM_HASH_H
