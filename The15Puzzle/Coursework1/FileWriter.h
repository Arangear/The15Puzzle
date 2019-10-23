//Author:        Daniel Cieslowski
//Date created:  16.10.2019
//Last modified: 23.10.2019
#pragma once
#include "FileManager.h"
#include "Puzzle.h"
#include <string>
#include <deque>
#include <fstream>

class FileWriter : public FileManager
{
public:
	void WritePuzzlesToFile(const std::string& filePath, const std::deque<Puzzle>& puzzles);
	void WriteSolutionsToFile(const std::string& filePath, const std::deque<Puzzle>& puzzles);

	friend void operator<<(FileWriter& fw, const Puzzle& puzzle);
	friend void operator<<(FileWriter& fw, const char* string);
	friend void operator<<(FileWriter& fw, const int& number);
private:
	std::ofstream stream;

	void openStream(const std::string& filePath);
	void closeStream();
};