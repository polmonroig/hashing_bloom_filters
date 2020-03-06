# variable definition
OPT = -O3
STD = -std=c++17
COMPILER = g++ $(OPT)
OUTNAME = -o experimenter

# directory definition
DATA = data/data_manager.cpp
DICTIONARYBLOOM = dictionary/bloom_filters/bloom_filters.cpp
DICTIONARY_CHAINING_LISTS = dictionary/separate_chaining/separate_chaining_lists.cpp
DICTIONARY_CHAINING_VECTOR = dictionary/separate_chaining/separate_chaining_vector.cpp
DICTIONARY_DOUBLE_HASHING = dictionary/open_hashing/double_hashing/double_hashing.cpp
DICTIONARY_COCKOO_HASHING = dictionary/open_hashing/cockoo_hashing/cockoo_hashing.cpp
DICTIONARY_LINEAR_PROBING = dictionary/open_hashing/linear_probing/linear_probing.cpp
DICTIONARY_QUADRATIC_PROBING = dictionary/open_hashing/quadratic_probing/quadratic_probing.cpp
EXPERIMENT = experiment/experiment.cpp
HASH_FUNCTIONS = hash/hash_functions/division_hash.cpp \
				 hash/hash_functions/multiplicative_hash.cpp
RANDOM = random/rand_generator.cpp
MAIN = experimenter.cpp

TARGET = $(RANDOM) $(DATA) $(HASH_FUNCTIONS) $(DICTIONARYBLOOM) \
		 $(DICTIONARY_CHAINING_LISTS) $(DICTIONARY_CHAINING_VECTOR) \
		 $(DICTIONARY_DOUBLE_HASHING) $(DICTIONARY_LINEAR_PROBING) $(DICTIONARY_QUADRATIC_PROBING) $(DICTIONARY_COCKOO_HASHING) \
		 $(EXPERIMENT)
 
# rule definition
experimenter: $(TARGET) $(MAIN)
	$(COMPILER) $(STD) $(TARGET) $(MAIN) $(OUTNAME)

clean:
		rm experimenter
