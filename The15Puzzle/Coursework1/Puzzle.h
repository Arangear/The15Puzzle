//Author:        Daniel Cieslowski
//Date created:  16.10.2019
//Last modified: 21.10.2019

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
	const int Size() const;
	const int ElementCount() const;
	const solution GetSolution() const;
	void SetSolution(const int rows, const int reversedRows, const int columns, const int reversedColumns);
	const int& operator()(const int x, const int y) const;
	int& operator()(const int x, const int y);
	const int& operator()(const int x) const;
	int& operator()(const int x);
	//IO
	friend std::ostream& operator<<(std::ostream& oStream, const Puzzle& puzzle);
private:
	static const int size = 4;
	static const int elementCount = size * size - 1;
	int state[elementCount];
	solution solution;
};