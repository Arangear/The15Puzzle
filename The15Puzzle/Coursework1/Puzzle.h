//Author:        Daniel Cieslowski
//Date created:  16.10.2019
//Last modified: 16.10.2019

#pragma once

#include <iostream>

//Class representing a 15-puzzle problem
class Puzzle
{
public:
	Puzzle();
	Puzzle(const Puzzle& puzzle);
	//Data access
	const int GetSize() const;
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
};