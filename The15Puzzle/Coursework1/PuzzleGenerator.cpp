//Author:        Daniel Cieslowski
//Date created:  18.10.2019
//Last modified: 18.10.2019
#include "PuzzleGenerator.h"

PuzzleGenerator::PuzzleGenerator() : seed(0)
{

}

PuzzleGenerator::PuzzleGenerator(const int seed) : seed(seed)
{

}

Puzzle PuzzleGenerator::Next()
{
	std::shuffle(&values[0], &values[19], std::default_random_engine(seed));
	return Puzzle(values);
}

void PuzzleGenerator::Generate(const int count)
{
	for (int i = 0; i < count; i++)
	{
		std::cout << Next() << "\n";
	}
}
