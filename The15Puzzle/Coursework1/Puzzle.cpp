//Author:        Daniel Cieslowski
//Date created:  16.10.2019
//Last modified: 19.10.2019
#include "Puzzle.h"
#include <limits>

Puzzle::Puzzle()
{

}

Puzzle::Puzzle(const int* values)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size; j++)
		{
			state[i][j] = values[i * size + j];
		}
	}
	for (int i = 0; i < size - 1; i++)
	{
		state[size - 1][i] = values[(size - 1) * size + i];
	}
	state[size - 1][size - 1] = values[size * size - 1];
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
	oStream << "\n";
	return oStream;
}

std::istream & operator>>(std::istream& iStream, Puzzle& puzzle)
{
	std::set<int> values;
	for (int i = 0; i < puzzle.GetSize() - 1; i++)
	{
		for (int j = 0; j < puzzle.GetSize(); j++)
		{
			puzzle.ensureValidInput(iStream, puzzle(i, j), values, i * puzzle.GetSize() + j + 1);
		}
	}
	for (int i = 0; i < puzzle.GetSize() - 1; i++)
	{
		puzzle.ensureValidInput(iStream, puzzle(puzzle.GetSize() - 1, i), values, puzzle.GetSize() * (puzzle.GetSize() - 1) + i + 1);
	}
	return iStream;
}

void Puzzle::ensureValidInput(std::istream& iStream, int& value, std::set<int>& values, const int& count)
{
	while (true)
	{
		std::cout << "Type in a unique number from 1 to 20: ";
		iStream >> value;
		if (iStream.fail() || value < 1 || value > 20)
		{
			std::cout << "Provided value is incorrect.\n";
			iStream.clear();
			iStream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
		{
			values.insert(value);
			if (values.size() != count)
			{
				std::cout << "This value was already provided.\n";
				iStream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else
			{
				iStream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				return;
			}
		}
	}
}