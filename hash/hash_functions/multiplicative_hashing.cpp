#include "multiplicative_hashing.h"


/** =================================
 *               PUBLIC
 *  =================================*/

MultiplicativeHashing::MultiplicativeHashing() {
    name = "MultiplicativeHashing";
}



unsigned int MultiplicativeHashing::operator()(int key, unsigned int tableSize) const {
    return floor(tableSize * ((fractionADivWord * key) % 1));
}
