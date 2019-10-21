//Author:        Daniel Cieslowski
//Date created:  17.10.2019
//Last modified: 21.10.2019
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
			if (allPuzzlesSolved)
			{
				printSolutionsToConsole();
				break;
			}
		case '9':
			if (allPuzzlesSolved)
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
	if (allPuzzlesSolved)
	{
		std::cout << "[8] Print all solutions to console\n";
		std::cout << "[9] Print all solutions to file\n";
	}
}

void UI::inputPuzzle()
{
	Puzzle puzzle;
	std::set<int> values;

	for (int i = 0; i < puzzle.ElementCount(); i++)
	{
		puzzle(i) = ensureValidInput(values, i + 1);
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

void UI::savePuzzles()
{
	std::string filePath = getFilePath("Type in path to the file you wish to save puzzles to: ");
	fileWriter.WritePuzzlesToFile(filePath, puzzles);
	std::cout << "All puzzles saved to " << filePath << "\n\n";
}

void UI::loadPuzzles()
{
	int initialCount = puzzles.size();
	std::string filePath;

	std::cout << "Provide a path to the file you wish to load in: ";
	std::cin >> filePath;

	switch (fileReader.LoadPuzzles(filePath, puzzles))
	{
	case success:
		std::cout << "Loaded in " << puzzles.size() - initialCount << " puzzles.\n\n";
		break;
	case readFail:
		std::cerr << "Data format in file incorrect.\n";
		std::cout << "Managed to load in " << puzzles.size() - initialCount << " puzzles.\n\n";
		break;
	case openFail:
		std::cerr << "Failed to open file " << filePath << "\n";
	}
	if (puzzles.size() - initialCount != 0)
	{
		allPuzzlesSolved = false;
	}
}

void UI::solvePuzzles()
{
	for (Puzzle& puzzle : puzzles)
	{
		solver.Solve(puzzle);
	}
	std::cout << "All puzzles' solutions found.\n\n";
	allPuzzlesSolved = true;
}

void UI::clearPuzzles()
{
	puzzles.clear();
	std::cout << "Successfully removed all the puzzles from memory.\n\n";
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

void UI::printSolutionsToFile()
{
	fileWriter.WriteSolutionsToFile("solution.txt", puzzles);
	std::cout << "All solutions saved to solution.txt\n\n";
}

int UI::ensureValidInput(std::set<int>& values, int count)
{
	int value;

	while (true)
	{
		std::cout << "Type in a unique number from 1 to 20: ";
		std::cin >> value;

		if (std::cin.fail() || value < 1 || value > 20)
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
				count++;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				return value;
			}
		}
	}
}

void UI::inputError(std::string message)
{
	std::cerr << message;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string UI::getFilePath(std::string message)
{
	std::string filePath;

	std::cout << message;
	std::cin >> filePath;

	return filePath;
}
