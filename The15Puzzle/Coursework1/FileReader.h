//Author:        Daniel Cieslowski
//Date created:  16.10.2019
//Last modified: 20.10.2019
#pragma once
#include "FileManager.h"
#include "Puzzle.h"
#include <deque>
#include <fstream>

class FileReader : public FileManager
{
public:
	void LoadPuzzles(const std::string& filePath, std::deque<Puzzle>& puzzles);
	friend void operator>>(FileReader& fileReader, Puzzle& puzzle);
private:
	std::ifstream stream;

	void openStream(const std::string& filePath);
	void closeStream();
	void loadPuzzles(const int& count, std::deque<Puzzle>& puzzles);
	void dataFormatError();
};