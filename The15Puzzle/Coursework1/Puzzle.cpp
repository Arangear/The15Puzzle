//Author:        Daniel Cieslowski
//Date created:  16.10.2019
//Last modified: 16.10.2019
#include "Puzzle.h"

Puzzle::Puzzle()
{

}

Puzzle::Puzzle(const Puzzle & puzzle)
{
	memcpy_s(&(*this)(0, 0), size*size * sizeof(int), &puzzle(0, 0), size*size * sizeof(int));
}

const int Puzzle::GetSize() const
{
	return size;
}

const int & Puzzle::operator()(const int x, const int y) const
{
	return state[x][y];
}

int & Puzzle::operator()(const int x, const int y)
{
	return state[x][y];
}

std::ostream & operator<<(std::ostream & oStream, const Puzzle & puzzle)
{
	for (int i = 0; i < puzzle.size; i++)
	{
		for (int j = 0; j < puzzle.size; j++)
		{
			oStream << puzzle(i, j) << " ";
		}
		oStream << "\n";
	}

	return oStream;
}
