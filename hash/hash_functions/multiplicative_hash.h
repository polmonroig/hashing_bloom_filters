#ifndef A_MULTIPLICATIVE_HASH_H
#define A_MULTIPLICATIVE_HASH_H

#include <cmath>

#include "hash_function.h"
#include "../../random/rand_generator.h"


/**
 * @class MultiplicativeHash
 * @brief hash multiplicative function
 *         referencing
 *         D.E. Knuth
 *         The art of computer programming
 *         volume 3[516]
 * */
class MultiplicativeHash : public HashFunction{

public:
    /**
    * @brief basic constructor, define the name
    * */
    MultiplicativeHash();

    /**
     * @brief hash function operator
     * @pre true
     * @post true
     * @param value is the key to be hashed
     * @param tableSize is the size of the hash table
     * @returns the hashed value of the key
     * */
    virtual unsigned int operator()(int key, unsigned int tableSize) const final ;

private:

    /**
     * @brief the word size of the computer
     * */
    const BigInt wordSize = 4294967296;

    /**
     * @brief constant relative prime to wordSize
     * */
    const BigInt A = 2654435761;

    /**
     * @brief the fraction of A div wordSize
     * */
    const BigInt fractionADivWord = A / wordSize;

};


#endif //A_MULTIPLICATIVE_HASH_H
