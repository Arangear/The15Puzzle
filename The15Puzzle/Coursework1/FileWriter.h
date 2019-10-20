//Author:        Daniel Cieslowski
//Date created:  16.10.2019
//Last modified: 20.10.2019
#pragma once
#include "FileManager.h"
#include "Puzzle.h"
#include <string>
#include <deque>

class FileWriter : public FileManager
{
public:
	void WritePuzzlesToFile(const char* filePath, std::deque<Puzzle>& puzzles);
	void WriteSolutionsToFile(const std::string& filePath, std::deque<Puzzle>& puzzles);
	void OpenStream(const std::string& filePath);
	void CloseStream();
	friend void operator<<(FileWriter& fw, const Puzzle& puzzle);
	friend void operator<<(FileWriter& fw, const char* string);
	friend void operator<<(FileWriter& fw, const int& number);
private:
	std::ofstream stream;
};