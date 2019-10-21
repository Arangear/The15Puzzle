//Author:        Daniel Cieslowski
//Date created:  16.10.2019
//Last modified: 21.10.2019
#pragma once
#include "FileManager.h"
#include "Puzzle.h"
#include <deque>
#include <fstream>

enum result { success, openFail, readFail };

//Class responsible for reading files and loading in puzzles.
class FileReader : public FileManager
{
public:
	//Method loading in puzzles to puzzles deque from file indicated by filePath.
	//Returns enum indicating if the operation was successful or if an error occurred.
	result LoadPuzzles(const std::string filePath, std::deque<Puzzle>& puzzles);
private:
	std::ifstream stream;

	void openStream(const std::string filePath);
	void closeStream();
	result loadPuzzles(const int count, std::deque<Puzzle>& puzzles);
};