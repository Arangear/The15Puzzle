//Author:        Daniel Cieslowski
//Date created:  18.10.2019
//Last modified: 19.10.2019
#include "PuzzleGenerator.h"
#include <random>

PuzzleGenerator::PuzzleGenerator()
{

}

Puzzle PuzzleGenerator::Next()
{
	std::random_device random;
	std::shuffle(&values[0], &values[19], std::default_random_engine(random()));
	return Puzzle(values);
}

void PuzzleGenerator::Generate(const int count, std::deque<Puzzle>& puzzles)
{
	for (int i = 0; i < count; i++)
	{
		puzzles.insert(puzzles.end(), Next());
	}
}
