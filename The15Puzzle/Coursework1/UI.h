#pragma once

#include "FileReader.h"
#include "FileWriter.h"

class UI
{
public:
	void Display();
private:
	FileReader fileReader;
	FileWriter fileWriter;

	void inputPuzzle(Puzzle& puzzle);
	void displayOptions();
	void generatePuzzles();
	void promptSave(const int count);
};