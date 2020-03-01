

data_generator : data_generator.cpp random/rand_generator.cpp
	g++ -O3 data_generator.cpp random/rand_generator.cpp -o data_generator
