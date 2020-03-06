#include <iostream>
using namespace std;

#include "double_hashing/double_hashing.h"
#include <vector>
#include "../../hash/hash_functions/division_hash.h"
#include "../../hash/hash_functions/multiplicative_hash.h"


int main() {

//per compilar g++ -std=c++17 -o main main.cpp double_hashing/double_hashing.cpp ../../hash/hash_functions/division_hash.cpp ../../hash/hash_functions/multiplicative_hash.cpp ../../hash/hash_functions/hash_function.cpp


	vector<int> keys{2,3,4,5};
	vector<int> text{2,3,4,5,2,3,3,3,6};

	DoubleHashing linear(keys.size(), DivisionHash(), MultiplicativeHash());

	for (int i = 0; i < text.size(); ++i) {
		if (linear.find(text[i])) cout <<"Key " << text[i] << " found." << endl;
		else {
			cout << "Key " << text[i] << " not found.";
			cout << endl;
			cout << "Linear " << linear.getPosition(text[i]) << endl;
			linear.insert(text[i]);
			for(int i = 0; i < keys.size(); ++i) {
				cout << linear.hashTable[i] << ' ';
			}
			cout << endl;
		}
	}


}