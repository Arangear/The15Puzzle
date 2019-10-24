//Author:        Daniel Cieslowski
//Date created:  23.10.2019
//Last modified: 23.10.2019
#pragma once

#include "Puzzle.h"

class Solver
{
public:
	//Methods

	//Finds the solution to the puzzle.
	void Solve(Puzzle& puzzle);
	//Finds partial solutions to the current configuration of the puzzle.
	void SolvePartialCurrent(Puzzle& puzzle);
	//Finds partial solutions to all the configurations of the puzzle reachable using valid turns.
	void SolvePartialAllTurns(Puzzle& puzzle);
private:
};
