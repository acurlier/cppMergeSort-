#include <iostream>
#include <vector>
#include <cstring>
#include <chrono>

#include "Generator.hpp"
#include "MergeSort.hpp"

using namespace std;
void callForHelp();

int main(int argc, char *argv[]) {

    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;
    
    Generator myGenerator;
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    int listLength(0);
    int wordLength(0);

    /*
    This program implements the mergesort algorithm based on vector<vector<char>> items that are randomly generated using two parameters :
    the length of the list to be sorted (listLength) and the length of the words on that list (wordLength).
    
    It allows two modes:
    
    -i listLength wordLength
        This mode is a user-defined performance assessment that asks for the the length of the list to be sorted (listLength) and the length of the words on that list (wordLength). 
    
    -p wordLength
        this mode is intended for performance comparison and verification of the O(n) time performance of the implementation of mergesort. It will successively run iterations of
        lists made of 10, 50, 100, 1000, 10000 and 100000 words and display the results in terms of execution time. The length of the words (wordLength) is provided by the user.
        The time taken to generate the random lists is not considered by the counter.

    */
    if (strcmp(argv[1], "-h")==0) {
        callForHelp();
    
    } else if (strcmp(argv[1], "-i")==0) { 

        if (argc != 4) {
            listLength = 30;
            wordLength = 10;
            cout << "Error in command line arguments. Using default values:" << endl;
            cout << "List length : 30"  << endl;
            cout << "Words length : 10"  << endl;
        } else {
            listLength = stoi(argv[2]);
            wordLength = stoi(argv[3]);
        }

        vector<vector<char>> outputDict = myGenerator.generateRandomList(listLength, wordLength, alpha);   
        //cout << "Init:" << endl;
        //Utility::printFrame(outputDict);

        auto t1 = high_resolution_clock::now();
        MergeSort myMergeSort(outputDict);
        myMergeSort.sortAndMerge(0,outputDict.size()-1);
        auto t2 = high_resolution_clock::now();

        cout << "Sorted:"<< endl;
        Utility::printFrame(outputDict);

        /* Getting number of milliseconds as an integer. */
        auto ms_int = duration_cast<milliseconds>(t2 - t1);
        /* Getting number of milliseconds as a double. */
        duration<double, milli> ms_double = t2 - t1;

        cout << ms_int.count() << "ms\n";
        cout << ms_double.count() << "ms\n";      

    } else  if (strcmp(argv[1], "-p")==0) { 

        vector<int> iterations({10000, 20000 ,50000 ,75000, 100000, 200000});

        if (argc != 3) {
            wordLength = 10;
            cout << "Error in command line arguments. Using default values:" << endl;

        } else {
            wordLength = stoi(argv[2]);
        }
        cout << "Performance assessment: words length: " <<  wordLength << endl;
        for (int i = 0; i < iterations.size(); i++)
        {
            vector<vector<char>> outputDict = myGenerator.generateRandomList(iterations[i], wordLength, alpha);
            auto t1 = high_resolution_clock::now();
            MergeSort myMergeSort(outputDict);
            myMergeSort.sortAndMerge(0,outputDict.size()-1);
            auto t2 = high_resolution_clock::now();

            auto ms_int = duration_cast<milliseconds>(t2 - t1);
            
            cout << i << " - " << iterations[i] << " words:\t";
            cout << ms_int.count() << "ms\n";

        }   
    } else {
        callForHelp();
    }
    
    return 0;

}

    // declare test vector

    /*
    vector<vector<char>> list(6,{'\0','\0','\0'});
    
	list[0] = {'a', 'a', 'a'};
    list[1] = {'r', 'b', 'b'};
    list[2] = {'i', 'b', 'a'};
    list[3] = {'c', 'a', 'b'};
    list[4] = {'z', 'c', 'b'};
    list[5] = {'a', 'b', 'b'};
    */

    void callForHelp() {
        cout << "This program implements the mergesort algorithm based on vector<vector<char>> items that are randomly generated using two parameters :\n- The length of the list to be sorted (listLength)\n- The length of the words on that list (wordLength).\n\nIt allows two modes of operation:\n" << endl; 
        
        cout << "-i listLength wordLength" << endl;
        cout << "\tThis mode is a user-defined performance assessment that asks for the length of the list to be sorted (listLength) and\nthe length of the words on that list (wordLength).\n\n" << endl;

        cout << "-p wordLength" << endl;
        cout << "\tThis mode is intended for performance comparison and verification of the O(n) time performance of the implementation of mergesort.\nIt will successively run iterations of lists made of 10, 50, 100, 1000, 10000 and 100000 words and display the results in terms of execution time.\nThe length of the words (wordLength) is provided by the user.\nThe time taken to generate the random lists is not considered by the counter."<< endl;
    }