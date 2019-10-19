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
		case '3':
			loadFile();
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
	std::cout << "[3] Load in files from file\n";
}

void UI::generatePuzzles()
{
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
			if (count < 1)
			{
				std::cout << "Number of puzzles to generate must be greater than 0.\n";
			}
			else
			{
				promptSave(count);
				return;
			}
		}
	}
}

void UI::promptSave(const int count)
{
	PuzzleGenerator pg(0);
	while (true)
	{
		char choice;
		std::cout << "Do you want to write generated puzzles to file? [Y/N]";
		std::cin >> choice;
		switch (choice)
		{
		case 'y':
		case 'Y':
			pg.Generate(count, fileWriter);
			return;
		case 'n':
		case 'N':
			pg.Generate(count);
			return;
		default:
			std::cout << "Unrecognised command.\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
}

void loadFile()
{

}