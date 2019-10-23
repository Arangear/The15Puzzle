//Author:        Daniel Cieslowski
//Date created:  23.10.2019
//Last modified: 23.10.2019
#include "PuzzleGenerator.h"

int main()
{
	//UI ui;
	//ui.Display();

	PuzzleGenerator pg(4);

	std::cout << pg.Next() << "\n\n";
	pg.Resize(5);
	std::cout << pg.Next() << "\n\n";
	pg.Resize(6);
	std::cout << pg.Next() << "\n\n";
	pg.Resize(2);
	std::cout << pg.Next() << "\n\n";

	return 0;
}