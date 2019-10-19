//Author:        Daniel Cieslowski
//Date created:  18.10.2019
//Last modified: 18.10.2019
#pragma once

#include "Puzzle.h"
#include "FileWriter.h"

class PuzzleGenerator
{
public:
	PuzzleGenerator();
	PuzzleGenerator(const int seed);
	Puzzle Next();
	void Generate(const int count);
	void Generate(const int count, FileWriter& fileWriter);
private:
	const int seed;
	int values[20] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
};