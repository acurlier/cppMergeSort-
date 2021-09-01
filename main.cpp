#include <iostream>
#include "Generator.hpp"

using namespace std;

int main() {
    
    int listLength(0);
    int wordLength(0);

    cout << "give list length:" << endl;
    cin >> listLength;    
    cout << "give word length:" << endl;
    cin >> wordLength;


    Generator myGenerator;
    string alpha = "abcdefghijklmnopqrstuvwxyz";


    vector<vector<char>> outputDict = myGenerator.generateRandomList(listLength, wordLength, alpha);   
    Utility::printFrame(outputDict);

    return 0;
}