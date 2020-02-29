//
// Created by pol on 2/29/20.
//

#include "multiplicative_hashing.h"


/** =================================
 *               PUBLIC
 *  =================================*/

MultiplicativeHashing::MultiplicativeHashing() {
    name = "MultiplicativeHashing";
    wordSize = 32;
    A = 2;
    fractionADivWord = A / wordSize;
}



unsigned int MultiplicativeHashing::operator()(int key, unsigned int tableSize) const {
    return floor(tableSize * ((fractionADivWord * key) % 1));
}
