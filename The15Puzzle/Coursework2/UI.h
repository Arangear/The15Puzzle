//Author:        Daniel Cieslowski
//Date created:  23.10.2019
//Last modified: 24.10.2019
#pragma once
#include "Solver.h"
#include "PuzzleGenerator.h"
#include "FileReader.h"
#include "FileWriter.h"
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
	FileWriter fileWriter;
	FileReader fileReader;
	Solver solver;
	std::deque<Puzzle> puzzles;

	//Displays the option menu.
	void displayOptions();
	void modifyProblemSize();
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
	//Displays a yes or no menu with a message.
	//Returns whether the answer was a yes.
	bool askYesOrNo(const std::string message);
	//Asks whether to emulate turns and returns translated user input.
	bool emulateTurns();
	//Asks whether to solve current configuration and returns translated user input.
	bool solveSingleState();
	//Asks whether to calculate the number of partial solutions and returns translated user input.
	bool findPartials();
	//Initiates solving the puzzle.
	void solvePuzzles();
	//Asks whether to emulate turns and returns translated user input.
	void findSolution(const bool turnsOn, const bool current, Puzzle& puzzle);
	//Clears puzzles from memory.
	void clearPuzzles();
	//Prints all solutions to console.
	void printSolutionsToConsole();
	//Prints all solutions to file.
	void printSolutionsToFile();

	//Validates input from user when typing in a puzzle.
	int ensureValidInput(std::set<int>& values, const int count, const int upper);
	//Displays an error message and clears input stream.
	void inputError(const std::string message);
	//Displays the choose file menu.
	//Returns filePath input from user.
	std::string getFilePath(const std::string message);
	//Displays whether opening filePath was successful based on result and if so displays message.
	void openFile(const result result, const std::string filePath, const std::string message);
};