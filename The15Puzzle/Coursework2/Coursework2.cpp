//Author:        Daniel Cieslowski
//Date created:  23.10.2019
//Last modified: 23.10.2019
#include "PuzzleGenerator.h"
#include "Solver.h"

int main()
{
	//UI ui;
	//ui.Display();

	Solver s;
	PuzzleGenerator pg(4);
	Puzzle p = pg.Next();
	std::cout << p << "\n\n";
	s.Solve(p);

	return 0;
}