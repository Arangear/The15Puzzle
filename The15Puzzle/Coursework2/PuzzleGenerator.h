//Author:        Daniel Cieslowski
//Date created:  23.10.2019
//Last modified: 24.10.2019
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

	//Generates a puzzle pseudo-randomly.
	Puzzle Next();
	//Generates a count puzzles in a random way and adds them to puzzles deque.
	void Generate(const int count, std::deque<Puzzle>& puzzles);
	//Changes the size of generated puzzles
	void Resize(const int _size);
private:
	//Size of the puzzle.
	int size;
	//Array of values that can appear in a puzzle.
	int* values;
};