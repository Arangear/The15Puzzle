//Author:        Daniel Cieslowski
//Date created:  18.10.2019
//Last modified: 18.10.2019
#pragma once

#include "Puzzle.h"

class PuzzleGenerator
{
public:
	PuzzleGenerator();
	PuzzleGenerator(const int seed);
	Puzzle Next();
	void Generate(const int count);
private:
	const int seed;
};