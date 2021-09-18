#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

#include "MergeSort.hpp"
#include "Generator.hpp"

using namespace std;

//implement MergeSort Method algorithm on a vector of vector<char> in order to get it alphabetically sorted

MergeSort::MergeSort(vector<vector<char>> &inputTable): m_inputTable(inputTable)  {

}

void MergeSort::sortAndMerge(const int &startIndex, const int &endIndex) 
{
    int midIndex(startIndex+(endIndex-startIndex)/2);

    if (startIndex < endIndex) // we stop when we reach the end of the decomposition (unitary elements)
    {
        sortAndMerge(startIndex, midIndex); // recursively call the sortAndMerge method on intervals that are smaller and smaller
        sortAndMerge(midIndex+1, endIndex);

        merge(startIndex, midIndex, endIndex); // this does all the work
    }
}

void MergeSort::merge(const int &startIndex, const int &midIndex, const int &endIndex)  {

    int nl, nr;
    //size of left and right sub-arrays
    nl = midIndex -startIndex+1;
    nr = endIndex-midIndex;

    // generate temporary vectors to store initial values to be sorted

    vector<vector<char>>::const_iterator firstl = m_inputTable.begin() + startIndex;
    vector<vector<char>>::const_iterator lastl = m_inputTable.begin() + midIndex;
    vector<vector<char>> larr(firstl, lastl+1);
    
    vector<vector<char>>::const_iterator firstr = m_inputTable.begin() + midIndex+1;
    vector<vector<char>>::const_iterator lastr = m_inputTable.begin() + endIndex;
    vector<vector<char>> rarr(firstr, lastr+1);

    int k(startIndex);
    int i(0), j(0);
    
    while(i < nl && j<nr) { //go through both temp vectors, sorting the element in the result vector
        if(MergeSort::isV1BeforeV2(larr[i],rarr[j])) {
            m_inputTable[k] = larr[i];
            i++;
        }else{
            m_inputTable[k] = rarr[j];
            j++;
        }
        k++;
    }

    while(i<nl) {       //fill the result vector with extra element in left temp vector (if any)
      m_inputTable[k] = larr[i];
      i++; 
      k++;
    }
    while(j<nr) {     //fill the result vector with extra element in right temp vector (if any)
      m_inputTable[k] = rarr[j];
      j++; 
      k++;
    }

}

bool MergeSort::isV1BeforeV2(const vector<char> &vector1, const vector<char> &vector2) {
/* 
function allowing to determine if a reference vector of char should be 
sorted before or after another vector of chars (called the comparator)
*/
    vector<char>* pointerRef(0);
    vector<char>* pointerComparator(0);

    bool vectorOneIsRef(0);

    if (vector1.size() < vector2.size()) { // the reference is the shortest vector
        pointerRef = const_cast<vector<char>*>(&vector1);
        pointerComparator = const_cast<vector<char>*>(&vector2);
        vectorOneIsRef = true;
    } else {
        pointerRef = const_cast<vector<char>*>(&vector2);
        pointerComparator = const_cast<vector<char>*>(&vector1);  
    }

    for (int i = 0; i < pointerRef->size(); i++) // we compare the elements of both strings
    {
        if ((((*pointerRef)[i] < (*pointerComparator)[i]) && vectorOneIsRef) || (((*pointerRef)[i] > (*pointerComparator)[i]) && !vectorOneIsRef)) { 
            return true;
        }
        else if ((((*pointerRef)[i] < (*pointerComparator)[i]) && !vectorOneIsRef) || (((*pointerRef)[i] > (*pointerComparator)[i]) && vectorOneIsRef)) {
            return false;
        }
    }
    return vectorOneIsRef; // if the comparator vector is longer than the ref, and that they are equal across the length of the ref, then the ref goes first 
}
