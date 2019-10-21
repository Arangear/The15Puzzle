//Author:        Daniel Cieslowski
//Date created:  16.10.2019
//Last modified: 21.10.2019
#pragma once
#include "FileManager.h"
#include "Puzzle.h"
#include <deque>
#include <fstream>

enum result { success, openFail, readFail };

class FileReader : public FileManager
{
public:
	result LoadPuzzles(const std::string filePath, std::deque<Puzzle>& puzzles);
private:
	std::ifstream stream;

	void openStream(const std::string& filePath);
	void closeStream();
	result loadPuzzles(const int count, std::deque<Puzzle>& puzzles);
};