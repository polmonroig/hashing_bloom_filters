#include "hash_function.h"


/** =================================
 *               PUBLIC
 *  =================================*/


std::string HashFunction::getName() const{
    return name;
}

unsigned int HashFunction::operator()(int key, unsigned int tableSize) const {
    return 0;
}
