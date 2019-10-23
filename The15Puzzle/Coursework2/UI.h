//Author:        Daniel Cieslowski
//Date created:  17.10.2019
//Last modified: 23.10.2019
#pragma once

#include "FileReader.h"
#include "FileWriter.h"
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

	int ensureValidInput(std::set<int>& values, const int count);
	void inputError(const std::string message);
	std::string getFilePath(const std::string message);
	void openFile(const result result, const std::string filePath, const std::string message);
};