//Author:        Daniel Cieslowski
//Date created:  23.10.2019
//Last modified: 23.10.2019
#pragma once

#include <iostream>

struct solution
{
	int rows = 0;
	int reversedRows = 0;
	int columns = 0;
	int reversedColumns = 0;
};

//Class representing a 15-puzzle problem.
class Puzzle
{
public:
	//Constructors

	Puzzle(const int size);
	Puzzle(const int size, const int* values);
	Puzzle(const Puzzle& puzzle);
	~Puzzle();

	//Methods

	//Returns whether the puzzle has already been solved or not.
	const bool IsSolved() const;
	//Marks the puzzle as solved.
	void Solve();
	//Returns the size of the puzzle.
	const int Size() const;
	//Returns the number of tiles in the puzzle.
	const int ElementCount() const;
	//Returns solution to the puzzle.
	const solution GetSolution() const;
	//Sets solution of the puzzle to the values indicated by arguments.
	void SetSolution(const int rows, const int reversedRows, const int columns, const int reversedColumns);

	//Operators

	//Allows constant value access to puzzle state as if state was a 2-dimensional array.
	const int& operator()(const int x, const int y) const;
	//Allows access to puzzle state as if state was a 2-dimensional array.
	int& operator()(const int x, const int y);
	//Allows constant value access to puzzle state.
	const int& operator()(const int x) const;
	//Allows access to puzzle state.
	int& operator()(const int x);

	friend std::ostream& operator<<(std::ostream& oStream, const Puzzle& puzzle);
private:
	const int size;
	const int elementCount;
	int* state;
	solution solution;
	bool solved = false;
};