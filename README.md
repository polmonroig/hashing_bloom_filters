# Hashing and Bloom filters key lookup comparison #
Repository for the implementation of different hashing techniques as well as 
a bloom filters data structure. Each data structure is tested with a series of experiments 
to compare their key lookup time and general performance. 

## Directory structure ##
This project is structured into 7 main folders 
    <li><b>src/</b> Contains all the code of the project including and the necessary files to compile it
    		   and run it</li>
    <li><b>docs/</b> Contains the documentation of the code, the documentation has a code 
    		    documentation in html that was created using Doxygen, and the documentation of the 
    		    experiment that contains the results and observations of the experiments with 
    		    all the plots</li>



## Compilation & execution ##
To compile the code you need to run  the Makefile with<br>
    ``` make```
    
To execute it has to be run with the specified parameters in usage<br>
	``` Usage: ./experimenter n load nHashFunctions seed keyPercentage inputDir outputDir

	    n: the number of keys to insert to the dictionary 
	    load: the load factor of the table, size of the table = n / loadFactor
	    nHashFunctions: the number of hash functions used by the bloom filters
	    seed: the random seed for the data generation
	    keyPercentage: the minimum percentage of keys that appear in the data text files
	    inputDir: the directory where the generated data must be placed, the directory must exist
	    outputDir: the directory where the experiment must be placed, the directory must exist

	```
	


