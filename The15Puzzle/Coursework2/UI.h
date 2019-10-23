//Author:        Daniel Cieslowski
//Date created:  23.10.2019
//Last modified: 23.10.2019
#pragma once

#include "Solver.h"
#include "PuzzleGenerator.h"
#include <set>

//Class responsible for communication between users and the application.
class UI
{
public:
	//Methods

	//Displays the user menu.
	void Display();
private:
	int problemSize = 4;
	bool allPuzzlesSolved = false;
	PuzzleGenerator puzzleGenerator;
	Solver solver;
	std::deque<Puzzle> puzzles;

	void displayOptions();
	void modifyProblemSize();
	void inputPuzzle();
	void generatePuzzles();
	void printPuzzles();
	//void savePuzzles();
	//void loadPuzzles();
	void solvePuzzles();
	void clearPuzzles();
	void printSolutionsToConsole();
	//void printSolutionsToFile();

	int ensureValidInput(std::set<int>& values, const int count, const int upper);
	void inputError(const std::string message);
	//std::string getFilePath(const std::string message);
};