//Author:        Daniel Cieslowski
//Date created:  23.10.2019
//Last modified: 24.10.2019
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
	//Returns enum indicating if the operation was successful or if an error occurred.
	result WritePuzzlesToFile(const std::string filePath, const std::deque<Puzzle>& puzzles);
	//Writes solutions from puzzles deque into file indicated by filePath.
	//Returns enum indicating if the operation was successful or if an error occurred.
	result WriteSolutionsToFile(const std::string filePath, std::deque<Puzzle>& puzzles);

	//Operators

	friend void operator<<(FileWriter& fw, const Puzzle& puzzle);
	friend void operator<<(FileWriter& fw, const std::string message);
	friend void operator<<(FileWriter& fw, const int number);
private:
	//Output stream.
	std::ofstream stream;
	//Opens the stream to the file indicated by filePath.
	//Returns whether it was successful or not.
	bool openStream(const std::string filePath);
	//Closes the open stream.
	void closeStream();
};