#include "UI.h"
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
		default:
			std::cout << "Unrecognised command.\n";
		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

void UI::inputPuzzle(Puzzle& puzzle)
{
	std::cout << "Please type in 15 different integer numbers from 1 to 20:\n";
	
	std::cin >> puzzle;

	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void UI::displayOptions()
{
	std::cout << "What do you want to do?\n";
	std::cout << "[0] Exit the application\n";
	std::cout << "[1] Type in a puzzle\n";
}
