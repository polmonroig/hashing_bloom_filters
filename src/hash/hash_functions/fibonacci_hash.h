#ifndef A_FIBONACCI_HASH_H
#define A_FIBONACCI_HASH_H

#include <cmath>

#include "hash_function.h"


/**
 * @class FibonacciHash
 * @brief hash multiplicative function
 *         referencing
 *         D.E. Knuth
 *         The art of computer programming
 *         volume 3[516]
 * */
class FibonacciHash : public HashFunction{

public:
    /**
    * @brief basic constructor, define the name
    * */
    FibonacciHash();

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
    const double wordSize = 4294967296;

    /**
     * @brief constant relative prime to wordSize
     * */
    const double A = 2654435761;

    /**
     * @brief the fraction of A div wordSize aprox. golden ratio = 0.61800399887
     * */
    const double fractionADivWord = double(A) / double(wordSize);

};


#endif //A_FIBONACCI_HASH_H
