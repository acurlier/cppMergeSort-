#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <random>


class Generator
{
    public:
    std::vector<std::vector<char>> generateRandomList(const int &listLength, const int &wordLength, const std::string &generatorAlpha);
    
};

class Utility
{
	public:
	static void printFrame(std::vector<std::vector<char>> &list);
};
