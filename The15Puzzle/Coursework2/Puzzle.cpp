//Author:        Daniel Cieslowski
//Date created:  23.10.2019
//Last modified: 24.10.2019
#include "Puzzle.h"

Puzzle::Puzzle(const int size) : size(size), elementCount(size * size - 1)
{
	state = new int[elementCount];
	partialSolutions = new int[size - 1];
	partialSolutionsAllTurns = new int[size - 1];
	for (int i = 0; i < size - 1; i++)
	{
		partialSolutions[i] = 0;
		partialSolutionsAllTurns[i] = 0;
	}
}

Puzzle::Puzzle(const int size, const int* values) : Puzzle(size)
{
	for (int i = 0; i < elementCount; i++)
	{
		state[i] = values[i];
	}
}

Puzzle::Puzzle(const Puzzle& puzzle) : Puzzle(puzzle.Size())
{
	for (int i = 0; i < elementCount; i++)
	{
		this->state[i] = puzzle.state[i];
	}
}

Puzzle::~Puzzle()
{
	delete[] state;
	delete[] partialSolutions;
	delete[] partialSolutionsAllTurns;
}

const bool Puzzle::IsSolved() const
{
	return solved;
}

const bool Puzzle::IsPartiallySolved() const
{
	return solvedPartial;
}

const bool Puzzle::IsPartiallySolvedAllTurns() const
{
	return solvedPartialAllTurns;
}

void Puzzle::Solve()
{
	solved = true;
}

void Puzzle::SolvePartially()
{
	solvedPartial = true;
}

void Puzzle::SolveAllTurnsPartially()
{
	solvedPartialAllTurns = true;
}

const int Puzzle::Size() const
{
	return size;
}

const int Puzzle::ElementCount() const
{
	return elementCount;
}

const solution Puzzle::GetSolution() const
{
	return solution;
}

void Puzzle::SetSolution(const int rows, const int reversedRows, const int columns, const int reversedColumns)
{
	solution = { rows, reversedRows, columns, reversedColumns };
}

int Puzzle::GetPartialSolution(bool allTurns, int partialNumber)
{
	return allTurns ? partialSolutionsAllTurns[partialNumber - 2] : partialSolutions[partialNumber - 2];
}

const int& Puzzle::operator()(const int x, const int y) const
{
	return state[x * size + y];
}

int& Puzzle::operator()(const int x, const int y)
{
	return state[x * size + y];
}

const int& Puzzle::operator()(const int x) const
{
	return state[x];
}

int& Puzzle::operator()(const int x)
{
	return state[x];
}

std::ostream& operator<<(std::ostream& oStream, const Puzzle& puzzle)
{
	for (int i = 0; i < puzzle.size - 1; i++)
	{
		for (int j = 0; j < puzzle.size; j++)
		{
			oStream << puzzle(i, j) << " ";
		}
		oStream << "\n";
	}
	for (int i = 0; i < puzzle.size - 1; i++)
	{
		oStream << puzzle(puzzle.size - 1, i) << " ";
	}

	return oStream;
}