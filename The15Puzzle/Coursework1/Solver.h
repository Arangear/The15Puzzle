#pragma once

#include "Puzzle.h"

struct solution 
{
	int rows = 0;
	int reversedRows = 0;
	int columns = 0;
	int reversedColumns = 0;
};

class Solver
{
public:
	Solver();
	solution Solve(Puzzle& puzzle);
private:

};