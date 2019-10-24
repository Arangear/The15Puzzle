//Author:        Daniel Cieslowski
//Date created:  18.10.2019
//Last modified: 24.10.2019
#pragma once
#include "Puzzle.h"
#include "FileWriter.h"
#include <random>
#include <deque>

//Class responsible for generating valid puzzles in a pseudo-random way.
class PuzzleGenerator
{
public:
	//Constructor

	PuzzleGenerator();

	//Methods

	//Generates a puzzle pseudo-randomly.
	Puzzle Next();
	//Generates a count puzzles in a random way and adds them to puzzles deque.
	void Generate(const int count, std::deque<Puzzle>& puzzles);
private:
	//Seed value for the random number generator.
	const int seed;
	//Array of values that can appear in a puzzle.
	int values[20] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
};