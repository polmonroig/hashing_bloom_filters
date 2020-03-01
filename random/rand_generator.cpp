//
// Created by pol on 3/1/20.
//

#include "rand_generator.h"


/** =================================
 *               PUBLIC
 *  =================================*/

typedef long long unsigned int BigInt;

RandGenerator::BigInt RandGenerator::generate(RandGenerator::BigInt seed) {
    return (seed * a + c) % m;
}

std::vector<BigInt> RandGenerator::generatePermutations(RandGenerator::BigInt seed, unsigned int size) {
    std::vector<BigInt> sequence(size);
    for(auto & element : sequence){
        element = generate(seed);
        seed = element;
    }
    return sequence;
}


