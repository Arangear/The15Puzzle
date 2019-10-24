//Author:        Daniel Cieslowski
//Date created:  20.10.2019
//Last modified: 24.10.2019
#pragma once

#include "Puzzle.h"

class Solver
{
public:
	//Methods

	//Finds the solution to puzzle.
	void Solve(Puzzle& puzzle);
private:
	//Returns the number of consecutive sets
	const int findConsecutiveSets(const Puzzle& puzzle);
	const unsigned long long int factorial(const int value);
};