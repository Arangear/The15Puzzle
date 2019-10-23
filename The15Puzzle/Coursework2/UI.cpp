//Author:        Daniel Cieslowski
//Date created:  23.10.2019
//Last modified: 23.10.2019
#include "UI.h"
#include <limits>
#include <string>

void UI::Display()
{
	std::cout << "Welcome to The 15 Puzzle!\n\n";
	while (true)
	{
		int choice;

		displayOptions();
		std::cin >> choice;

		if (std::cin.fail())
		{
			inputError("Unrecognised command.\n");
			continue;
		}
		
		switch (choice)
		{
		case 0:
			return;
		case 1:
			modifyProblemSize();
			break;
		case 2:
			inputPuzzle();
			break;
		case 3:
			generatePuzzles();
			break;
		case 4:
			printPuzzles();
			break;
		case 5:
			//savePuzzles();
			break;
		case 6:
			//loadPuzzles();
			break;
		case 7:
			solvePuzzles();
			break;
		case 8:
			clearPuzzles();
			break;
		case 9:
			if (allPuzzlesSolved)
			{
				printSolutionsToConsole();
				break;
			}
		case 10:
			if (allPuzzlesSolved)
			{
				//printSolutionsToFile();
				break;
			}
		default:
			inputError("Unrecognised command.\n");
		}
	}
}

void UI::displayOptions()
{
	std::cout << "Current problem size: " << problemSize << ".\n";
	std::cout << "What do you want to do?\n";
	std::cout << "[0] Exit the application\n";
	std::cout << "[1] Change the problem size (This will clear all puzzles from memory)\n";
	std::cout << "[2] Type in a puzzle\n";
	std::cout << "[3] Generate puzzles randomly\n";
	std::cout << "[4] Print puzzles from memory\n";
	std::cout << "[5] Save puzzles from memory to file\n";
	std::cout << "[6] Load puzzles from file to memory\n";
	std::cout << "[7] Solve all puzzles in memory\n";
	std::cout << "[8] Remove all puzzles from memory\n";
	if (allPuzzlesSolved)
	{
		std::cout << "[9] Print all solutions to console\n";
		std::cout << "[10] Print all solutions to file\n";
	}
}

void UI::modifyProblemSize()
{
	while (true)
	{
		int oldValue = problemSize;
		std::cout << "Type in new size of the problem (4 or more): ";
		std::cin >> problemSize;
		if (std::cin.fail() || problemSize < 4)
		{
			inputError("Provided value is incorrect.\n");
		}
		else if (oldValue == problemSize)
		{
			inputError("Provided value is exactly the same as the current one. Returning to main menu.\n\n");
			return;
		}
		else
		{
			puzzles.clear();
			allPuzzlesSolved = false;
			puzzleGenerator.Resize(problemSize);
			std::cout << "Problem size is now " << problemSize << ".\n\n";
			return;
		}
	}
}

void UI::inputPuzzle()
{
	Puzzle puzzle(problemSize);
	std::set<int> values;
	int upperValueBound = problemSize * (problemSize + 1);

	for (int i = 0; i < puzzle.ElementCount(); i++)
	{
		puzzle(i) = ensureValidInput(values, i + 1, upperValueBound);
	}
	std::cout << "\n";

	puzzles.insert(puzzles.end(), puzzle);
	allPuzzlesSolved = false;
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
			allPuzzlesSolved = false;
			return;
		}
	}
}

void UI::printPuzzles()
{
	if (puzzles.empty())
	{
		std::cout << "No puzzles in memory.\n\n";
		return;
	}
	for (Puzzle& puzzle : puzzles)
	{
		std::cout << puzzle << "\n\n";
	}
}

void UI::solvePuzzles()
{
	for (Puzzle& puzzle : puzzles)
	{
		if (!puzzle.IsSolved())
		{
			solver.Solve(puzzle);
		}
	}
	std::cout << "All puzzles' solutions found.\n\n";
	allPuzzlesSolved = true;
}

void UI::clearPuzzles()
{
	puzzles.clear();
	std::cout << "Removed all the puzzles from memory.\n\n";
	allPuzzlesSolved = false;
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

int UI::ensureValidInput(std::set<int>& values, const int count, const int upper)
{
	int value;

	while (true)
	{
		std::cout << "Type in a unique number from 1 to " << upper << ": ";
		std::cin >> value;

		if (std::cin.fail() || value < 1 || value > upper)
		{
			inputError("Provided value is incorrect.\n");
		}
		else
		{
			values.insert(value);

			if (values.size() != count)
			{
				inputError("This value was already provided.\n");
			}
			else
			{
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				return value;
			}
		}
	}
}

void UI::inputError(const std::string message)
{
	std::cerr << message;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
