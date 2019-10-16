//Author:        Daniel Cieslowski
//Date created:  16.10.2019
//Last modified: 16.10.2019

#include "Puzzle.h"

int main()
{
	Puzzle p1;
	Puzzle p2;
	for (int i = 0; i < p2.GetSize(); i++)
	{
		for (int j = 0; j < p2.GetSize(); j++)
		{
			p2(i, j) = i * (i + 1) + j - 3;
		}
	}
	Puzzle p3(p2);
	std::cout << p1 << "\n" << p2 << "\n" << p3;

	return 0;
}