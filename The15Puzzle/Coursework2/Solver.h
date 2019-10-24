//Author:        Daniel Cieslowski
//Date created:  23.10.2019
//Last modified: 24.10.2019
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
	//Returns the number of consecutive sets of a given size.
	const int findConsecutiveSets(const Puzzle& puzzle, const int size);
	//Calculates the factorial of value and returns it.
	const cpp_int factorial(const int value);
	//Counts specified partials in the given configuration
	void countPartials(Puzzle& puzzle, const int partialNumber);
	//Returns whether there is a partial continuous row in the puzzle starting in position (x,y)
	bool isContinuousRow(Puzzle& puzzle, const int x, const int y, const int partialNumber);
	//Returns whether there is a partial continuous reversed row in the puzzle starting in position (x,y)
	bool isContinuousReversedRow(Puzzle& puzzle, const int x, const int y, const int partialNumber);
	//Returns whether there is a partial continuous column in the puzzle starting in position (x,y)
	bool isContinuousColumn(Puzzle& puzzle, const int x, const int y, const int partialNumber);
	//Returns whether there is a partial continuous reversed column in the puzzle starting in position (x,y)
	bool isContinuousReversedColumn(Puzzle& puzzle, const int x, const int y, const int partialNumber);
};
