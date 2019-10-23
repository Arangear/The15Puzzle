//Author:        Daniel Cieslowski
//Date created:  23.10.2019
//Last modified: 23.10.2019
#pragma once

#include "Puzzle.h"
#include <random>
#include <deque>

//Class responsible for generating valid puzzles in a pseudo-random way.
class PuzzleGenerator
{
public:
	//Constructor

	PuzzleGenerator();
	~PuzzleGenerator();

	//Methods

	//Generates another random puzzle.
	Puzzle Next();
	//Generates a count puzzles in a random way and adds them to puzzles deque.
	void Generate(const int count, std::deque<Puzzle>& puzzles);
	//Changes the size of generated puzzles
	void Resize(const int _size);
private:
	int size;
	const int seed;
	int* values;
};