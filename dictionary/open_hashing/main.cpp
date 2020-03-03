#include <iostream>
using namespace std;

#include "open_hashing.h"
#include <vector>

int main() {

//per compilar g++ -o main main.cpp open_hashing.cpp ../dictionary.cpp ../../hash/hash_functions/division_hash.cpp 

	vector<int> keys{2,3,4,5};
	vector<int> text{2,3,4,5,2,3,3,3};

	OpenHashing linear(keys.size(), DivisionHash());

	if (linear.find(keys[0])) cout <<"Key " << keys[0] << "found.";
	else cout << "Key " << keys[0] << "not found.";

	linear.insert(keys[0]);

	for(int i = 0; i < keys.size(); ++i) {
		cout << linear.hashTable[i] << ' ' << endl;
	}

}