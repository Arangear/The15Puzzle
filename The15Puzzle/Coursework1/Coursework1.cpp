//Author:        Daniel Cieslowski
//Date created:  16.10.2019
//Last modified: 18.10.2019

//#include "FileWriter.h"
//#include "FileReader.h"
#include "UI.h"
#include "PuzzleGenerator.h"
#include <iostream>

int main()
{
	//UI ui;
	//ui.Display();
	PuzzleGenerator pg(50);
	std::cout << pg.Next() << "\n";
	std::cout << pg.Next() << "\n";
	std::cout << pg.Next() << "\n";
	std::cout << pg.Next() << "\n";

	return 0;
}