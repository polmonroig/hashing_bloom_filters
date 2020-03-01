#include <iostream>

#include "random/rand_generator.h"

int main(){

    auto numbers = RandGenerator::generatePermutations(4156156, 500);
    for(auto const& number : numbers){
        std::cout << number << std::endl;
    }

    return 0;
}