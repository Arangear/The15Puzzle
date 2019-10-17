#pragma once

#include "Puzzle.h"

class UI
{
public:
	void Display();
private:
	void inputPuzzle(Puzzle& puzzle);
	void displayOptions();
};