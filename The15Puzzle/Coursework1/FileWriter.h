//Author:        Daniel Cieslowski
//Date created:  16.10.2019
//Last modified: 18.10.2019
#pragma once
#include "FileManager.h"
#include "Puzzle.h"

class FileWriter : public FileManager
{
public:
	void OpenStream(const std::string& filePath);
	void CloseStream();
	friend void operator<<(FileWriter& fw, const Puzzle& puzzle);
	friend void operator<<(FileWriter& fw, const char* string);
	friend void operator<<(FileWriter& fw, const int& number);
private:
	std::ofstream stream;
};