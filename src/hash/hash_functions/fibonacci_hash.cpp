#include "fibonacci_hash.h"


/** =================================
 *               PUBLIC
 *  =================================*/

FibonacciHash::FibonacciHash() {
    name = "FibonacciHash";
}

unsigned int FibonacciHash::operator()(int key, unsigned int tableSize) const {
    double temp = fractionADivWord  * key;
    double fractionalPart = temp - int(temp);
    return int(tableSize * fractionalPart);
}
