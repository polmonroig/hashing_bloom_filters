#include "experiment.h"


/* =================================
 *               PUBLIC
 *  =================================*/

Experiment::Experiment(Dictionary  &dict) {
    dictionary = &dict;
}



void Experiment::test(std::vector<int> const &keys, std::vector<int> const &text) {
    std::cout << "Number of keys: " << keys.size() << std::endl;
    std::cout << "Number of texts: " << text.size() << std::endl;
    buildTable(keys);
    buildTime = getElapsedTime();
    collisions = dictionary->getCollisions();
    std::cout << "Colisions: " << collisions << std::endl;
    searchElements(text);
    unsigned int falsePositives = successLookupTimes - keys.size() / 2;
    std::cout << "False positives: " << falsePositives << std:: endl;
}

std::string Experiment::getCollisions() const{
    return std::to_string(collisions);
}

std::string Experiment::getBuildTime() const{
    return std::to_string(buildTime);
}


/* =================================
 *               PRIVATE
 *  =================================*/


void Experiment::buildTable(const std::vector<int> &vector) {
    startTimer();
    for(auto const& value : vector){
        dictionary->insert(value);
    }
    endTimer();
}

void Experiment::searchElements(const std::vector<int> &vector) {
    successLookupTimeMean = 0;
    failLookupTimeMean = 0;
    successLookupTimes = 0;
    failLookupTimes = 0;
    for(auto const& value : vector) {
        startTimer();
        bool found = dictionary->find(value);
        endTimer();
        double lookupTime = getElapsedTime();
        if (found) {
            successLookupTimes++;
            successLookupTimeMean += lookupTime;
        } else {
            failLookupTimes++;
            failLookupTimeMean += lookupTime;
        }
    }

    if(successLookupTimes > 0)
        successLookupTimeMean /= successLookupTimes;
    if(failLookupTimes > 0)
        failLookupTimeMean /= failLookupTimes;

    std::cout << "Succesful lookups: " << successLookupTimes << std::endl;
    std::cout << "Succesful mean lookup time: " <<successLookupTimeMean << std::endl;
    std::cout << "Failed lookups: " << failLookupTimes << std::endl;
    std::cout << "Failed mean lookup time: " <<failLookupTimeMean << std::endl;


}

void Experiment::startTimer() {
    startPoint = std::chrono::steady_clock::now();
}

void Experiment::endTimer() {
    endPoint = std::chrono::steady_clock::now();
}

double Experiment::getElapsedTime() const {
    return std::chrono::duration_cast<std::chrono::microseconds>(endPoint - startPoint).count();
}

std::string Experiment::getSuccesMeanTime() const {
    return std::to_string(successLookupTimeMean);
}

std::string Experiment::getFailMeanTime() const{
    return std::to_string(failLookupTimeMean);
}

