//Author:        Daniel Cieslowski
//Date created:  23.10.2019
//Last modified: 23.10.2019
#include "PuzzleGenerator.h"
#include <random>

PuzzleGenerator::PuzzleGenerator(): size(4)
{
	values = new int[size * (size + 1)];
	for (int i = 0; i < size * (size + 1); i++)
	{
		values[i] = i + 1;
	}
}

PuzzleGenerator::~PuzzleGenerator()
{
	delete[] values;
}

Puzzle PuzzleGenerator::Next()
{
	std::random_device random;
	std::shuffle(&values[0], &values[size * (size + 1) - 1], std::default_random_engine(random()));
	return Puzzle(size, values);
}

void PuzzleGenerator::Generate(const int count, std::deque<Puzzle>& puzzles)
{
	for (int i = 0; i < count; i++)
	{
		puzzles.insert(puzzles.end(), Next());
	}
}

void PuzzleGenerator::Resize(const int _size)
{
	size = _size;

	delete[] values;
	values = new int[size * (size + 1)];
	for (int i = 0; i < size * (size + 1); i++)
	{
		values[i] = i + 1;
	}
}
