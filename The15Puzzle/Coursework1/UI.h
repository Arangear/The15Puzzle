//Author:        Daniel Cieslowski
//Date created:  17.10.2019
//Last modified: 20.10.2019
#pragma once

#include "FileReader.h"
#include "FileWriter.h"
#include "Solver.h"
#include "PuzzleGenerator.h"
#include <set>

class UI
{
public:
	void Display();
private:
	bool solved = false;
	PuzzleGenerator puzzleGenerator;
	FileReader fileReader;
	FileWriter fileWriter;
	Solver solver;
	std::deque<Puzzle> puzzles;

	void displayOptions();
	void inputError(std::string message);
	void inputPuzzle();
	void generatePuzzles();
	void printPuzzles();
	void savePuzzles();
	void loadPuzzles();
	void solvePuzzles();
	void clearPuzzles();
	void printSolutionsToConsole();
	void printSolutionsToFile();
	int ensureValidInput(std::set<int>& values, int count);
};