#include <iostream>
using namespace std;

#include "cockoo_hashing/cockoo_hashing.h"
#include <vector>
#include "../../hash/hash_functions/division_hash.h"
#include "../../hash/hash_functions/multiplicative_hash.h"


int main() {

//per compilar g++ -std=c++17 -o main main.cpp cockoo_hashing/cockoo_hashing.cpp ../../hash/hash_functions/division_hash.cpp ../../hash/hash_functions/multiplicative_hash.cpp ../../hash/hash_functions/hash_function.cpp


	vector<int> keys{2,3,4,5,10,15};
	vector<int> text{2,3,4,5,10,15,6,11,12,13};

	auto h1 = DivisionHash();
	auto h2 = MultiplicativeHash();

	CockooHashing linear(10, h1, h2, 4);

	for (int i = 0; i < text.size(); ++i) {
		if (linear.find(text[i])) cout <<"Key " << text[i] << " found." << endl;
		else {
			cout << "Key " << text[i] << " not found.";
			cout << endl;
			pair<unsigned int, unsigned int> p = linear.getPositions(text[i]);
			cout << "Linear " << p.first << " " << p.second << endl;
			linear.insert(text[i]);
			for(int i = 0; i < 10; ++i) {
				cout << linear.hashTable[i] << ' ';
			}
			cout << endl;
		}
	}


}