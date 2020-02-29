#ifndef A_HASH_FUNCTION_H
#define A_HASH_FUNCTION_H

#include <string>


/**
 * @class Abstract definition of a hash function, a hash function
 *        can be called and it has a respective name
 * */
class HashFunction {

public:


    /**
     * @brief call the hash function operator
     * @pre depends on the subclass
     * @post true
     * @param value is the key to be hashed
     * @param tableSize is the size of the hash table
     * @returns the hashed value of the key
     * */
    virtual unsigned int operator()(int key, unsigned int tableSize) const;

    /**
     * @brief getter for the name of the hash function
     * @pre true
     * @post true
     * @returns the hash function name
     * */
    std::string getName() const;

protected:

    /**
     * @brief name of the function to be called, serves as id
     * */
    std::string name;

};


#endif //A_HASH_FUNCTION_H
