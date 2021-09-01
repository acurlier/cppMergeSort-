#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

#include "MergeSort.hpp"

using namespace std;

//implement MergeSort Method algorithm on a vector of vector<char> in order to get it alphabetically sorted
// from c++11,

MergeSort::MergeSort():{

}

vector<vector<char>> MergeSort::sortAndMerge(vector<vector<char>> inputTable){


}

vector<vector<char>> MergeSort::sort(vector<vector<char>> tableFragment){
        /* 
        sorts a vector composed of 2 vector<char> or arbitrary length
        */
    if (tableFragment[0][1] < tableFragment[0][0]) // in case the 2 elements are not in the right order
    {
        iter_swap(tableFragment.begin(),tableFragment.begin()+1);
    }
    
    

}

vector<vector<char>> MergeSort::merge(vector<vector<char>> vector1, vector<vector<char>> vector2){
    /*
    merges 2 vector<vector<char>> of arbitrary length that must have 
    been previously been alphabetically sorted / merged
    */

   int sizetotal = sizeof(vector1) + sizeof(vector2);
   for (int i = 0; i < sizetotal; i++)
   {
       if 
   }
   

   





}
