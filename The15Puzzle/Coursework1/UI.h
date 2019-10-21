//Author:        Daniel Cieslowski
//Date created:  17.10.2019
//Last modified: 21.10.2019
#pragma once

#include "FileReader.h"
#include "FileWriter.h"
#include "Solver.h"
#include "PuzzleGenerator.h"
#include <set>

//class responsible for communication between users and the application
class UI
{
public:
	void Display();
private:
	bool allPuzzlesSolved = false;
	PuzzleGenerator puzzleGenerator;
	FileReader fileReader;
	FileWriter fileWriter;
	Solver solver;
	std::deque<Puzzle> puzzles;

	void displayOptions();
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
	void inputError(std::string message);
	std::string getFilePath(std::string message);
};