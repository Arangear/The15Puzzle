//Author:        Daniel Cieslowski
//Date created:  17.10.2019
//Last modified: 20.10.2019
#include "UI.h"
#include <limits>

void UI::Display()
{
	std::cout << "Welcome to The 15 Puzzle!\n\n";
	while (true)
	{
		char choice;

		displayOptions();
		std::cin >> choice;

		switch (choice)
		{
		case '0':
			return;
		case '1':
			inputPuzzle();
			break;
		case '2':
			generatePuzzles();
			break;
		case '3':
			printPuzzles();
			break;
		case '4':
			savePuzzles();
			break;
		case '5':
			loadPuzzles();
			break;
		case '6':
			solvePuzzles();
			break;
		case '7':
			clearPuzzles();
			break;
		case '8':
			if (solved)
			{
				printSolutionsToConsole();
				break;
			}
		case '9':
			if (solved)
			{
				printSolutionsToFile();
				break;
			}
		default:
			inputError("Unrecognised command.\n");
		}
	}
}

void UI::displayOptions()
{
	std::cout << "What do you want to do?\n";
	std::cout << "[0] Exit the application\n";
	std::cout << "[1] Type in a puzzle\n";
	std::cout << "[2] Generate puzzles randomly\n";
	std::cout << "[3] Print puzzles from memory\n";
	std::cout << "[4] Save puzzles from memory to file\n";
	std::cout << "[5] Load puzzles from file to memory\n";
	std::cout << "[6] Solve all puzzles in memory\n";
	std::cout << "[7] Remove all puzzles from memory\n";
	if (solved)
	{
		std::cout << "[8] Print all solutions to console\n";
		std::cout << "[9] Print all solutions to file\n";
	}
}

void UI::inputError(const char * string)
{
	std::cerr << "Provided value is incorrect.\n";
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void UI::inputPuzzle()
{
	Puzzle puzzle;
	std::cin >> puzzle;
	std::cout << "\n";
	puzzles.insert(puzzles.end(), puzzle);
	solved = false;
}

void UI::generatePuzzles()
{
	std::cout << "How many puzzles do you wish to generate? [0 - return] ";
	while (true)
	{
		unsigned int count;
		std::cin >> count;
		if (std::cin.fail())
		{
			inputError("Provided value is incorrect.\n");
		}
		else if (count == 0)
		{
			return;
		}
		else
		{
			puzzleGenerator.Generate(count, puzzles);
			solved = false;
			return;
		}
	}
}

void UI::printPuzzles()
{
	if (puzzles.empty())
	{
		std::cout << "No puzzles in memory.\n";
		return;
	}
	for (Puzzle& puzzle : puzzles)
	{
		std::cout << puzzle << "\n\n";
	}
}

void UI::savePuzzles()
{
	fileWriter.WritePuzzlesToFile("15-file.txt", puzzles);
	std::cout << "All puzzles saved to 15-File.txt\n\n";
}

void UI::loadPuzzles()
{
	int initialCount = puzzles.size();
	std::string filePath;

	std::cout << "Provide a path to the file you wish to load in: ";
	std::cin >> filePath;
	fileReader.LoadPuzzles(filePath, puzzles);
	std::cout << "Loaded in " << puzzles.size() - initialCount << " puzzles.\n\n";
	if (puzzles.size() - initialCount == 0)
	{
		solved = false;
	}
}

void UI::solvePuzzles()
{
	for (Puzzle& puzzle : puzzles)
	{
		solver.Solve(puzzle);
	}
	std::cout << "All puzzles' solutions found.\n\n";
	solved = true;
}

void UI::clearPuzzles()
{
	puzzles.clear();
	std::cout << "Successfully removed all the puzzles from memory.\n\n";
	solved = false;
}

void UI::printSolutionsToConsole()
{
	std::cout << puzzles.size() << "\n";
	for (Puzzle& puzzle : puzzles)
	{
		std::cout << puzzle << "\n";
		std::cout << "row " << puzzle.GetSolution().rows << "\n";
		std::cout << "column " << puzzle.GetSolution().columns << "\n";
		std::cout << "reverse row " << puzzle.GetSolution().reversedRows << "\n";
		std::cout << "reverse column " << puzzle.GetSolution().reversedColumns << "\n\n";
	}
}

void UI::printSolutionsToFile()
{
	fileWriter.WriteSolutionsToFile("solution.txt", puzzles);
	std::cout << "All solutions saved to solution.txt\n\n";
}
