#include <iostream>

#include "experiment/experiment_manager.h"


void usage(){
    std::cerr << "Usage: ./experimenter n load nHashFunctions seed keyPercentage inputDir outputDir" << std::endl << std::endl;
    std::cerr << "    n: the number of keys to insert to the dictionary " << std::endl;
    std::cerr << "    load: the load factor of the table, size of the table = n / loadFactor" << std::endl;
    std::cerr << "    nHashFunctions: the number of hash functions used by the bloom filters" << std::endl;
    std::cerr << "    seed: the random seed for the data generation" << std::endl;
    std::cerr << "    keyPercentage: the minimum percentage of keys that appear in the data text files" << std::endl;
    std::cerr << "    inputDir: the directory where the generated data must be placed, the directory must exist" << std::endl;
    std::cerr << "    outputDir: the directory where the experiment must be placed, the directory must exist" << std::endl << std::endl;
}

int main(int argc, char* argv[]){

    if(argc < 8 || argc > 8 ){
        usage();
        return 1;
    }

    // PARAMETER DEFINITION
    int n = std::stoi(argv[1]);
    float loadFactor = std::stof(argv[2]);
    int tableSize = float(n) / loadFactor;
    int nHashFunctions = std::stoi(argv[3]);
    int seed = std::stoi(argv[4]);
    float keyPercentage = std::stof(argv[5]);
    std::string inputPath = argv[6];
    if(inputPath[inputPath.size() - 1] != '/')inputPath += '/';
    std::string outputPath = argv[7];
    if(inputPath[outputPath.size() - 1] != '/')outputPath += '/';

    ExperimentManager manager;
    manager.setParameters(n, loadFactor, tableSize, nHashFunctions,
                          seed, keyPercentage, inputPath, outputPath);

    manager.test();


    return 0;
}
