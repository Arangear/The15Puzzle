//Author:        Daniel Cieslowski
//Date created:  16.10.2019
//Last modified: 18.10.2019

#pragma once
#include <iostream>
#include <set>

struct solution
{
	int rows = 0;
	int reversedRows = 0;
	int columns = 0;
	int reversedColumns = 0;
};

//Class representing a 15-puzzle problem
class Puzzle
{
public:
	Puzzle();
	Puzzle(const int* values);
	Puzzle(const Puzzle& puzzle);
	//Data access
	const int GetSize() const;
	const solution GetSolution() const;
	void SetSolution(const int rows, const int reversedRows, const int columns, const int reversedColumns);
	const int& operator()(const int x, const int y) const;
	int& operator()(const int x, const int y);
	//IO
	friend std::ostream& operator<<(std::ostream& oStream, const Puzzle& puzzle);
	friend std::istream& operator>>(std::istream& iStream, Puzzle& puzzle);
private:
	static const int size = 4;
	int state[size][size] = { {1, 2, 3, 4}, 
							  {5, 6, 7, 8}, 
							  {9, 10, 11, 12}, 
							  {13, 14, 15, -1}};
	solution solution;

	void ensureValidInput(std::istream& iStream, int& value, std::set<int>& values, const int& count);
};