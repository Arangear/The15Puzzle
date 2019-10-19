//Author:        Daniel Cieslowski
//Date created:  17.10.2019
//Last modified: 19.10.2019
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
			break;
		case '5':
			break;
		case '6':
			break;
		case '7':
			break;
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
	std::cout << "[4] Save puzzles from memory to a file\n";
	std::cout << "[5] Load puzzles from file to memory\n";
	std::cout << "[6] Provide solutions to puzzles in memory\n";
	std::cout << "[7] Remove all puzzles from memory\n";
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
		std::cout << puzzle << "\n";
	}
}

void UI::loadFile()
{

}