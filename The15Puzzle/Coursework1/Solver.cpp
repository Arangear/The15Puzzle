//Author:        Daniel Cieslowski
//Date created:  20.10.2019
//Last modified: 24.10.2019
#include "Solver.h"
#include <algorithm>

void Solver::Solve(Puzzle& puzzle)
{
	int consecutiveCount = findConsecutiveSets(puzzle);
	unsigned long long int result = consecutiveCount * factorial(puzzle.ElementCount() - puzzle.Size()) * (puzzle.Size() - 1) / 2;
	puzzle.SetSolution(result, result, result, result);
	puzzle.Solve();
}

const int Solver::findConsecutiveSets(const Puzzle& puzzle)
{
	int* values = new int[puzzle.ElementCount()];
	int setCount = 0;

	for (int i = 0; i < puzzle.ElementCount(); i++)
	{
		values[i] = puzzle(i);
	}

	std::sort(values, values + puzzle.ElementCount());

	for (int i = 0; i < puzzle.ElementCount() - puzzle.Size() + 1; i++)
	{
		if (values[i] + 3 == values[i + puzzle.Size() - 1])
		{
			setCount++;
		}
	}

	delete[] values;
	return setCount;
}

const unsigned long long int Solver::factorial(const int value)
{
	unsigned long long int factorial = 1;

	for (int i = 1; i <= value; i++)
	{
		factorial *= i;
	}

	return factorial;
}
