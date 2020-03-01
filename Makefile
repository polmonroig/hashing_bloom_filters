

data_generator : data_generator.cpp random/rand_generator.cpp
	g++ -O3 data_generator.cpp random/rand_generator.cpp -o data_generator


docs : docs/documentation.tex
	rm docs/documentation.pdf
	pdflatex docs/documentation.tex docs/documentation.pdf
