#pragma once

#include <iostream>
#include <fstream>
#include <vector>


class MergeSort
{

public:

MergeSort(std::vector<std::vector<char>> &inputTable);
void sortAndMerge(const int &startIndex,const int &endIndex);

private:

std::vector<std::vector<char>> &m_inputTable; 
void merge(const int &startIndex, const int &midIndex, const int &endIndex);
bool isV1BeforeV2(std::vector<char> const &ref, std::vector<char> const &compared);



};