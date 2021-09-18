#include <iostream>
#include <fstream>
#include <vector>
#include <random>

#include "Generator.hpp"

using namespace std;

void Utility::printFrame(vector<vector<char>> &list) {
	int lineIndex = 0;
	if (list.size()==0)
	{
		cout << "Nothing to print !!" << endl;
	}
	
	for (int i = 0; i < list.size(); i++) {
		lineIndex = lineIndex+1;
		cout << lineIndex << " ";
		for (int j = 0; j < list[i].size(); j++) {
			cout << list[i][j] << "";
		}
	cout << endl;
	}
}

vector<vector<char>> Generator::generateRandomList(const int &listLength, const int &wordLength, const std::string &generatorAlpha) {
	const int range_to = generatorAlpha.length() - 1;
	const int range_from = 0;	

    vector<vector<char>> list (listLength);
	vector<char> line(wordLength);
	
	for (int j = 0; j < listLength; ++j) {
		random_device rand_dev; // generate initial value
		mt19937 generator(rand_dev()); // generate raw random number
		// genertate output from uniform distribution
		uniform_int_distribution<int> distr(range_from, range_to);

	for (int i = 0; i < wordLength; ++i) {
		auto const randomNumber = distr(generator);
		line[i] = generatorAlpha[randomNumber];
		}
	list[j] = line;
	}

return list;

}

