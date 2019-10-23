//Author:        Daniel Cieslowski
//Date created:  23.10.2019
//Last modified: 23.10.2019
#pragma once
#include "FileManager.h"
#include "Puzzle.h"
#include <deque>
#include <fstream>

//Class responsible for reading files and loading in puzzles.
class FileReader : public FileManager
{
public:
	//Methods

	//Method loading in puzzles to puzzles deque from file indicated by filePath.
	//Returns enum indicating if the operation was successful or if an error occurred.
	result LoadPuzzles(const std::string filePath, const int size, std::deque<Puzzle>& puzzles);
private:
	std::ifstream stream;

	bool openStream(const std::string filePath);
	void closeStream();
	result loadPuzzles(const int count, const int size, std::deque<Puzzle>& puzzles);
};