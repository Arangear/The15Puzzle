//Author:        Daniel Cieslowski
//Date created:  16.10.2019
//Last modified: 21.10.2019
#include "Puzzle.h"

Puzzle::Puzzle()
{

}

Puzzle::Puzzle(const int* values)
{
	for (int i = 0; i < elementCount; i++)
	{
		state[i] = values[i];
	}
}

Puzzle::Puzzle(const Puzzle & puzzle)
{
	memcpy_s(&(*this)(0, 0), elementCount * sizeof(int), &puzzle(0, 0), elementCount * sizeof(int));
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

std::ostream & operator<<(std::ostream & oStream, const Puzzle & puzzle)
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