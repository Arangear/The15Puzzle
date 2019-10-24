//Author:        Daniel Cieslowski
//Date created:  20.10.2019
//Last modified: 24.10.2019
#pragma once
#include "Puzzle.h"

class Solver
{
public:
	//Finds the solution to the puzzle.
	void Solve(Puzzle& puzzle);
private:
	//Returns the number of consecutive sets.
	const int findConsecutiveSets(const Puzzle& puzzle);
	//Calculates the factorial of value and returns it.
	const unsigned long long int factorial(const int value);
};