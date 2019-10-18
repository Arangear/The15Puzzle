//Author:        Daniel Cieslowski
//Date created:  17.10.2019
//Last modified: 18.10.2019
#include "UI.h"
#include "PuzzleGenerator.h"
#include <limits>

void UI::Display()
{
	Puzzle puzzle;

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
			inputPuzzle(puzzle);
			std::cout << puzzle;
			break;
		case '2':
			generatePuzzles();
			break;
		default:
			std::cout << "Unrecognised command.\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
}

void UI::inputPuzzle(Puzzle& puzzle)
{
	std::cin >> puzzle;
}

void UI::displayOptions()
{
	std::cout << "What do you want to do?\n";
	std::cout << "[0] Exit the application\n";
	std::cout << "[1] Type in a puzzle\n";
	std::cout << "[2] Generate puzzles randomly\n";
}

void UI::generatePuzzles()
{
	PuzzleGenerator pg(0);

	std::cout << "How many puzzles do you wish to generate? ";
	while (true)
	{
		int count;
		std::cin >> count;
		if (std::cin.fail())
		{
			std::cout << "Provided value is incorrect.\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
		{
			pg.Generate(count);
			return;
		}
	}
}