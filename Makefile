# variable definition
OPT = -O3
STD = -std=c++17
COMPILER = g++ $(OPT)
OUTNAME = -o experimenter

# directory definition
DATA = data/data_manager.cpp
DICTIONARY = dictionary/bloom_filters/bloom_filters.cpp
EXPERIMENT = experiment/experiment.cpp
HASH_FUNCTIONS = hash/hash_functions/hash_function.cpp \
 				 hash/hash_functions/division_hash.cpp \
				 hash/hash_functions/multiplicative_hash.cpp
RANDOM = random/rand_generator.cpp
MAIN = experimenter.cpp

TARGET = $(RANDOM) $(DATA) $(HASH_FUNCTIONS) $(DICTIONARY) $(EXPERIMENT)

# rule definition
experimenter: $(TARGET)
	$(COMPILER) $(STD) $(TARGET) $(MAIN) $(OUTNAME)

docs : docs/documentation.tex
	rm docs/documentation.pdf
	pdflatex docs/documentation.tex docs/documentation.pdf
