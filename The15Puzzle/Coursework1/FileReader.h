//Author:        Daniel Cieslowski
//Date created:  16.10.2019
//Last modified: 17.10.2019
#pragma once
#include "FileManager.h"
#include "Puzzle.h"

class FileReader : public FileManager
{
public:
	void OpenStream(const std::string& filePath);
	void CloseStream();
	friend void operator>>(FileReader& fileReader, Puzzle& puzzle);
private:
	std::ifstream stream;
};