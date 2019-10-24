//Author:        Daniel Cieslowski
//Date created:  23.10.2019
//Last modified: 23.10.2019
#include "Solver.h"

void Solver::Solve(Puzzle& puzzle)
{
	puzzle.Solve();
}

void Solver::SolvePartialCurrent(Puzzle & puzzle)
{
	puzzle.SolvePartially();
}

void Solver::SolvePartialAllTurns(Puzzle & puzzle)
{
	puzzle.SolveAllTurnsPartially();
}
