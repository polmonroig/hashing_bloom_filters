#include "multiplicative_hash.h"


/** =================================
 *               PUBLIC
 *  =================================*/

MultiplicativeHash::MultiplicativeHash() {
    name = "MultiplicativeHash";
}



unsigned int MultiplicativeHash::operator()(int key, unsigned int tableSize) const {
    return ((A * key) % wordSize) % tableSize ;
}
