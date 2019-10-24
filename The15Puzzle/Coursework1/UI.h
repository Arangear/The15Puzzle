//Author:        Daniel Cieslowski
//Date created:  17.10.2019
//Last modified: 24.10.2019
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

	//Displays the option menu.
	void displayOptions();
	//Displays puzzle input menu.
	void inputPuzzle();
	//Displays the generate puzzles menu.
	void generatePuzzles();
	//Prints puzzles from memory.
	void printPuzzles();
	//Displays the save to file menu.
	void savePuzzles();
	//Displays the load from file menu.
	void loadPuzzles();
	//Solves puzzles from memory.
	void solvePuzzles();
	//Clears puzzles from memory.
	void clearPuzzles();
	//Prints all solutions to console.
	void printSolutionsToConsole();
	//Prints all solutions to file.
	void printSolutionsToFile();

	//Validates input from user when typing in a puzzle.
	int ensureValidInput(std::set<int>& values, const int count);
	//Displays an error message and clears input stream.
	void inputError(const std::string message);
	//Displays the choose file menu.
	//Returns filePath input from user.
	std::string getFilePath(const std::string message);
	//Displays whether opening filePath was successful based on result and if so displays message.
	void openFile(const result result, const std::string filePath, const std::string message);
};