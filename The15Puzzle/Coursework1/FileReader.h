//Author:        Daniel Cieslowski
//Date created:  16.10.2019
//Last modified: 24.10.2019
#pragma once
#include "FileManager.h"
#include "Puzzle.h"
#include <deque>
#include <fstream>

//Class responsible for reading files and loading in puzzles.
class FileReader : public FileManager
{
public:
	//Method loading in puzzles to puzzles deque from file indicated by filePath.
	//Returns enum indicating if the operation was successful or if an error occurred.
	result LoadPuzzles(const std::string filePath, std::deque<Puzzle>& puzzles);
private:
	//Input stream
	std::ifstream stream;
	//Opens the stream to the file indicated by filePath.
	//Returns whether it was successful or not.
	bool openStream(const std::string filePath);
	//Closes the open stream.
	void closeStream();
	//Loads count puzzles to puzzles deque.
	//Returns the result of the operation.
	result loadPuzzles(const int count, std::deque<Puzzle>& puzzles);
};