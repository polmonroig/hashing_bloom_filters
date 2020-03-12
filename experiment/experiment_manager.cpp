#include "experiment_manager.h"

/* =================================
 *               PUBLIC
 *  =================================*/

void ExperimentManager::setParameters(int n, float loadFactor, int tableSize, int nHashFunctions,
                      int seed, int nRounds, float keyPercentage, std::string const& inputPath,
                      std::string const& outputPath){

      this->n = n;
      this->loadFactor = loadFactor;
      this->tableSize = tableSize;
      this->nHashFunctions = nHashFunctions;
      this->seed = seed;
      this->nRounds = nRounds;
      this->keyPercentage = keyPercentage;
      this->inputPath = inputPath;
      this->outputPath = outputPath;

}


void ExperimentManager::test(){
    // get data
    generateData();
    // DICTIONARIES DEFINITION
    auto h1 = DivisionHash();
    auto h2 = FibonacciHash();
    auto h3 = RandomHash();

    DoubleHashing dh(tableSize, h1, h2);
    LinearProbing lp(tableSize, h2);
    QuadraticProbing qp(tableSize, h1);
    BloomFilters bf(tableSize, nHashFunctions, h1, h2);
    CuckooHashing ck(tableSize, h1, h2, n / 2);
    SeparateChainingLists spl(tableSize, h2);
    SeparateChainingVector spv(tableSize, h2);

    std::list<Dictionary*> dictionaries{&dh,&lp, &qp, &ck, &spl, &spv, &bf};

    auto names = generateNames();
    CsvFile experimentFile(outputPath);
    CsvRow colNames = generateColNames();
    experimentFile.addRow(colNames);

    int i = 0;
    auto keys = data.getIntegerKeys(inputPath);
    auto text = data.getIntegerText(inputPath);
    for(auto const& dictionary : dictionaries){
        std::cout << "=================================" << std::endl;
        std::cout << "Testing " << names[i] << std::endl;
        for(int round = 0; round < nRounds; ++round){
            Experiment experiment(*dictionary);
            experiment.test(keys, text);
            auto row = generateRow(experiment, names[i]);
            experimentFile.addRow(row);
            auto keys = data.getIntegerKeys(inputPath);
            auto text = data.getIntegerText(inputPath);
        }
        ++i;
    }


    // SAVE DATA TO FILE
    experimentFile.write();

}




/* =================================
 *               PRIVATE
 *  =================================*/


void ExperimentManager::generateData(){
    if(seed == -1){
        int currentTime = std::chrono::duration_cast<std::chrono::seconds>(now).count();
        data.setSeed(currentTime);
    }
    else{
        data.setSeed(seed);
    }

    data.setSize(n);
    // creates the files if they do not exist already
    data.generateIntegerData(inputPath, keyPercentage);
}




std::vector<std::string> ExperimentManager::generateNames(){
    return  std::vector<std::string>{"DH", "LP", "QP", "CK", "SPL", "SPV", "BF"};
}




CsvRow ExperimentManager::generateColNames(){
    return  CsvRow{"dictionaryType", "n", "loadFactor", "nHashFunctions",
                    "seed", "keyPercentage", "avgSuccessProbes", "avgFailProbes",
                    "buildTime", "successMeanTime", "failMeanTime", "successMaxTime",
                    "successMinTime", "failMaxTime", "failMinTime", "falsePositives",
                    "successTheoricalValue", "failTheoricalValue"};
}


CsvRow ExperimentManager::generateRow(Experiment const& experiment, std::string const& name){
    return CsvRow{name,
               std::to_string(n), std::to_string(loadFactor), std::to_string(nHashFunctions),
               std::to_string(seed), std::to_string(keyPercentage), std::to_string(experiment.getSuccessProbes()),
               std::to_string(experiment.getFailProbes()),
               std::to_string(experiment.getBuildTime()), std::to_string(experiment.getSuccessMeanTime()),
               std::to_string(experiment.getFailMeanTime()), std::to_string(experiment.getSuccessMaxTime()),
               std::to_string(experiment.getSuccessMinTime()), std::to_string(experiment.getFailMaxTime()),
               std::to_string(experiment.getFailMinTime()),
               std::to_string(experiment.getFalsePositives()), std::to_string(experiment.getSuccessTheoricalValue(loadFactor)),
               std::to_string(experiment.getFailTheoricalValue(loadFactor))};

}
