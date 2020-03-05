#include <iostream>
using namespace std;

#include "linear_probing/linear_probing.h"
#include <vector>

int main() {

//per compilar g++ -o main main.cpp linear_probing/linear_probing.cpp ../dictionary.cpp ../../hash/hash_functions/division_hash.cpp ../../hash/hash_functions/hash_function.cpp

	vector<int> keys{2,3,4,5};
	vector<int> text{2,3,4,5,2,3,3,3,6};

	LinearProbing linear(keys.size(), DivisionHash());

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