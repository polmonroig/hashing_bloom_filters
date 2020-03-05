# Hashing and Bloom filters key lookup comparison #
Repository for the implementation of different hashing techniques as well as 
a bloom filters data structure. Each data structure is tested with a series of experiments 
to compare their key lookup time and general performance. 

## Directory structure ##
This project is structured into 7 main folders 
    <li><b>data/</b> Contains the data generator and the keys and texts used of the experiments</li>
    <li><b>dictionary/</b> Contains each of the data structures used for the tests</li>
    <li><b>docs/</b> Contains the documentation of the code (html) and the experiment research</li>
    <li><b>experiment/</b> Contains the definition of an experiment</li>
    <li><b>hash/</b> Contains different hash functions implementations</li>
    <li><b>random/</b> Contains the implementation of the random keys generator</li>
    <li><b>resources/</b> Contains implementation resources of hash tables</li>


## Compilation & execution ##
To compile the code you need to run <br>
    ``` make experimenter```
    
To execute it just run the binary output, the compilation of the code used C++17 