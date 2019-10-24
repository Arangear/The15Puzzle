//Author:        Daniel Cieslowski
//Date created:  23.10.2019
//Last modified: 24.10.2019
#pragma once
#include <iostream>

//Struct holding the solution to the puzzle data.
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
	//Returns whether the puzzle has already been solved for partial solutions or not.
	const bool IsPartiallySolved() const;
	//Returns whether the puzzle has already been solved for partial solutions in all valid combinations or not.
	const bool IsPartiallySolvedAllTurns() const;
	//Marks the puzzle as solved.
	void Solve();
	//Marks the puzzle as solved in regard to partial solutions in this configuration of the puzzle.
	void SolvePartially();
	//Marks the puzzle as solved in regard to partial solutions in all reachable configurations of the puzzle.
	void SolveAllTurnsPartially();
	//Returns the size of the puzzle.
	const int Size() const;
	//Returns the number of tiles in the puzzle.
	const int ElementCount() const;
	//Returns solution to the puzzle.
	const solution GetSolution() const;
	//Sets solution of the puzzle to the values indicated by arguments.
	void SetSolution(const int rows, const int reversedRows, const int columns, const int reversedColumns);
	//Returns the total number of requested partial solutions if it has been calculated.
	int GetPartialSolution(bool allTurns, int partialNumber);

	//Operators

	//Allows constant value access to puzzle state as if state was a 2-dimensional array.
	const int& operator()(const int x, const int y) const;
	//Allows access to puzzle state as if state was a 2-dimensional array.
	int& operator()(const int x, const int y);
	//Allows constant value access to puzzle state.
	const int& operator()(const int x) const;
	//Allows access to puzzle state.
	int& operator()(const int x);
	//Allows outputing puzzle in a stream
	friend std::ostream& operator<<(std::ostream& oStream, const Puzzle& puzzle);
private:
	//Size of the problem.
	int size;
	//Number of elements in the puzzle.
	int elementCount;
	//State of the puzzle.
	int* state;
	//Number of solutions.
	solution solution;
	//Array of all partial solutions for this configuration.
	int* partialSolutions;
	//Array of all partial solutions for all turns.
	int* partialSolutionsAllTurns;
	//Indicates whether the puzzle has been solved already.
	bool solved = false;
	//Indicates whether the puzzle has been solved partially already.
	bool solvedPartial = false;
	//Indicates whether the puzzle has been solved partially for all Turns already.
	bool solvedPartialAllTurns = false;
};