//Author:        Daniel Cieslowski
//Date created:  23.10.2019
//Last modified: 24.10.2019
#include "Solver.h"
#include <algorithm>

void Solver::Solve(Puzzle& puzzle)
{
	int consecutiveCount = findConsecutiveSets(puzzle, puzzle.Size());
	cpp_int result = consecutiveCount * factorial(puzzle.ElementCount() - puzzle.Size()) * (puzzle.Size() - 1) / 2;
	puzzle.SetSolution(result, result, result, result);
	puzzle.Solve();
}

void Solver::SolvePartialCurrent(Puzzle& puzzle)
{
	for (int i = 2; i <= puzzle.Size(); i++)
	{
		countPartials(puzzle, i);
	}
	puzzle.SolvePartially();
}

void Solver::SolvePartialAllTurns(Puzzle& puzzle)
{
	for (int i = 2; i <= puzzle.Size(); i++)
	{
		cpp_int consecutiveCount = findConsecutiveSets(puzzle, i);
		cpp_int possiblePlacements = (puzzle.Size() - i + 1) * puzzle.Size() - 1;
		puzzle.GetPartialSolution(true, i) = 2 * possiblePlacements * consecutiveCount * factorial(puzzle.Size() * puzzle.Size() - i - 1);
	}
	puzzle.SolveAllTurnsPartially();
}

const int Solver::findConsecutiveSets(const Puzzle& puzzle, const int size)
{
	int* values = new int[puzzle.ElementCount()];
	int setCount = 0;

	for (int i = 0; i < puzzle.ElementCount(); i++)
	{
		values[i] = puzzle(i);
	}

	std::sort(values, values + puzzle.ElementCount());

	for (int i = 0; i < puzzle.ElementCount() - size + 1; i++)
	{
		if (values[i] + size - 1 == values[i + size - 1])
		{
			setCount++;
		}
	}

	delete[] values;
	return setCount;
}

const cpp_int Solver::factorial(const int value)
{
	cpp_int factorial = 1;

	for (int i = 1; i <= value; i++)
	{
		factorial *= i;
	}

	return factorial;
}

void Solver::countPartials(Puzzle& puzzle, const int partialNumber)
{
	cpp_int count = 0;
	for (int i = 0; i < puzzle.Size(); i++)
	{
		for (int j = 0; j < puzzle.Size() - partialNumber + 1; j++)
		{
			if (isContinuousRow(puzzle, i, j, partialNumber))
			{
				count++;
			}
			if (isContinuousReversedRow(puzzle, i, j, partialNumber))
			{
				count++;
			}
		}
	}
	for (int i = 0; i < puzzle.Size() - partialNumber + 1; i++)
	{
		for (int j = 0; j < puzzle.Size(); j++)
		{
			if (isContinuousColumn(puzzle, i, j, partialNumber))
			{
				count++;
			}
			
			if (isContinuousReversedColumn(puzzle, i, j, partialNumber))
			{
				count++;
			}
		}
	}
	puzzle.GetPartialSolution(false, partialNumber) = count;
}

bool Solver::isContinuousRow(Puzzle & puzzle, const int x, const int y, const int partialNumber)
{
	bool continuous = true;
	for (int k = 0; k < partialNumber - 1; k++)
	{
		if (x == puzzle.Size() - 1 && y + k + 1 == puzzle.Size() - 1)
		{
			continuous = false;
			break;
		}
		if (puzzle(x, y + k) + 1 != puzzle(x, y + k + 1))
		{
			continuous = false;
			break;
		}
	}
	return continuous;
}

bool Solver::isContinuousReversedRow(Puzzle & puzzle, const int x, const int y, const int partialNumber)
{
	bool continuous = true;
	for (int k = 0; k < partialNumber - 1; k++)
	{
		if (x == puzzle.Size() - 1 && y + k + 1 == puzzle.Size() - 1)
		{
			continuous = false;
			break;
		}
		if (puzzle(x, y + k) - 1 != puzzle(x, y + k + 1))
		{
			continuous = false;
			break;
		}
	}
	return continuous;
}

bool Solver::isContinuousColumn(Puzzle & puzzle, const int x, const int y, const int partialNumber)
{
	bool continuous = true;
	for (int k = 0; k < partialNumber - 1; k++)
	{
		if (y == puzzle.Size() - 1 && x + k + 1 == puzzle.Size() - 1)
		{
			continuous = false;
			break;
		}
		if (puzzle(x + k, y) + 1 != puzzle(x + k + 1, y))
		{
			continuous = false;
			break;
		}
	}
	return continuous;
}

bool Solver::isContinuousReversedColumn(Puzzle & puzzle, const int x, const int y, const int partialNumber)
{
	bool continuous = true;
	for (int k = 0; k < partialNumber - 1; k++)
	{
		if (x == puzzle.Size() - 1 && y + k + 1 == puzzle.Size() - 1)
		{
			continuous = false;
			break;
		}
		if (puzzle(x + k, y) - 1 != puzzle(x + k + 1, y))
		{
			continuous = false;
			break;
		}
	}
	return continuous;
}
