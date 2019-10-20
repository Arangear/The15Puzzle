//Author:        Daniel Cieslowski
//Date created:  17.10.2019
//Last modified: 19.10.2019
#pragma once

#include "FileReader.h"
#include "FileWriter.h"
#include "Solver.h"
#include "PuzzleGenerator.h"

class UI
{
public:
	void Display();
private:
	PuzzleGenerator puzzleGenerator;
	FileReader fileReader;
	FileWriter fileWriter;
	Solver solver;
	std::deque<Puzzle> puzzles;

	void displayOptions();
	void inputError(const char* string);
	void inputPuzzle();
	void generatePuzzles();
	void printPuzzles();
	void savePuzzles();
	void loadPuzzles();
	void solvePuzzles();
	void clearPuzzles();
};