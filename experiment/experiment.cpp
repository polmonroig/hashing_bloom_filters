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
    searchElements(text);
    falsePositives = successLookupTimes - (text.size() - keys.size() * 2);
    std::cout << "False positives: " << falsePositives << std:: endl;
}

double Experiment::getSuccessProbes() const{
  return successProbes;
}


double Experiment::getFailProbes() const{
  return failProbes;
}

BigDouble Experiment::getBuildTime() const{
    return buildTime;
}

BigDouble Experiment::getSuccessMeanTime() const {
    return successLookupTimeMean;
}

BigDouble Experiment::getFailMeanTime() const{
    return failLookupTimeMean;
}

int Experiment::getFalsePositives() const{
    return falsePositives;
}

double Experiment::getSuccessMaxTime() const {
    return successMaxLookupTime;
}

double Experiment::getFailMaxTime() const {
    return failMaxLookupTime;
}

double Experiment::getSuccessMinTime() const {
    return successMinLookupTime;
}

double Experiment::getFailMinTime() const {
    return failMinLookupTime;
}


double Experiment::getSuccessTheoricalValue(float load_factor) const{
  return dictionary->getTheoricalValue(true, load_factor);
}


double Experiment::getFailTheoricalValue(float load_factor) const{
  return dictionary->getTheoricalValue(false, load_factor);
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
    failMaxLookupTime = 0;
    successProbes = 0;
    failProbes = 0;
    successMaxLookupTime = 0;
    failMinLookupTime = std::numeric_limits<double>::max();
    successMinLookupTime = std::numeric_limits<double >::max();
    for(auto const& value : vector) {
        startTimer();
        bool found = dictionary->find(value);
        endTimer();
        double lookupTime = getElapsedTime();
        if (found) {
            successLookupTimes++;
            successLookupTimeMean += lookupTime;
            if(lookupTime > successMaxLookupTime)successMaxLookupTime = lookupTime;
            if(lookupTime < successMinLookupTime)successMinLookupTime = lookupTime;
            successProbes += dictionary->getCollisions();
        } else {
            failLookupTimes++;
            failLookupTimeMean += lookupTime;
            if(lookupTime > failMaxLookupTime)failMaxLookupTime = lookupTime;
            if(lookupTime < failMinLookupTime)failMinLookupTime = lookupTime;
            failProbes += dictionary->getCollisions();
        }
    }


    if(successLookupTimes > 0){
      successLookupTimeMean /= successLookupTimes;
      successProbes /= successLookupTimes; 
    }
    if(failLookupTimes > 0){
      failLookupTimeMean /= failLookupTimes;
      failProbes /= failLookupTimes;
    }


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
