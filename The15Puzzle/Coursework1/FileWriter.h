//Author:        Daniel Cieslowski
//Date created:  16.10.2019
//Last modified: 21.10.2019
#pragma once
#include "FileManager.h"
#include "Puzzle.h"
#include <string>
#include <deque>
#include <fstream>

//Class responsible for writing puzzles and solutions to files.
class FileWriter : public FileManager
{
public:
	//Methods

	//Writes puzzles from puzzles deque into file indicated by filePath.
	void WritePuzzlesToFile(const std::string filePath, std::deque<Puzzle>& puzzles);
	//Writes solutions from puzzles deque into file indicated by filePath.
	void WriteSolutionsToFile(const std::string filePath, std::deque<Puzzle>& puzzles);

	//Operators

	friend void operator<<(FileWriter& fw, const Puzzle& puzzle);
	friend void operator<<(FileWriter& fw, const std::string message);
	friend void operator<<(FileWriter& fw, const int number);
private:
	std::ofstream stream;

	void openStream(const std::string filePath);
	void closeStream();
};