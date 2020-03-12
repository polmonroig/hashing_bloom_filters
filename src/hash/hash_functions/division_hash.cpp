#include "division_hash.h"

/** =================================
 *               PUBLIC
 *  =================================*/


DivisionHash::DivisionHash() {
    name = "DivisionHash";
}


unsigned int DivisionHash::operator()(int key, unsigned int tableSize) const {
    return key % tableSize;
}



/** =================================
 *               PRIVATE
 *  =================================*/