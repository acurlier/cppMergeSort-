# cppMergeSort

## Description
This program implements the mergesort algorithm on vector<vector> items that are randomly generated. It provides options to the user to evaluate the performance and display results.
This mainly served me as an introduction to cpp programming and algorithm implementation.

## Installation
You will need g++ to compile this program - it is intended to work with c++11 and above.

Clone this repertory, move it where you like and set it as your current directory

Compile the source using:
g++ -o app -Wall main.cpp Generator.cpp MergeSort.cpp

run the executable using ./app followed by the arguments as explained in the next section

## Usage
The program allows two modes of operation:
    
    -i listLength wordLength

This mode is a user-defined performance assessment that asks for the the length of the list to be sorted (listLength) and the length of the words on that list (wordLength). 
    
    -p wordLength

this mode is intended for performance comparison and verification of the O(n) time performance of the implementation of mergesort. It will successively run iterations of lists made of 10000, 20000 ,50000 ,75000, 100000 and 200000 words and display the results in terms of execution time. The length of the words (wordLength) is provided by the user. The time taken to generate the random lists is not considered by the counter.

## Project status
Closed

