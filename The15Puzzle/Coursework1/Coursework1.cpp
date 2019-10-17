//Author:        Daniel Cieslowski
//Date created:  16.10.2019
//Last modified: 17.10.2019

#include "FileWriter.h"
#include "FileReader.h"
#include <iostream>

int main()
{
	FileWriter fw;
	FileReader fr;

	std::string path("solution1.txt");

	Puzzle puzzle;

	std::cout << puzzle;

	fr.OpenStream("solution1.txt");

	fr >> puzzle;

	fr.CloseStream();

	std::cout << puzzle;

	return 0;
}