//Author:        Daniel Cieslowski
//Date created:  16.10.2019
//Last modified: 17.10.2019
#pragma once
#include "FileManager.h"
#include "Puzzle.h"
#include <string>

class FileWriter : public FileManager
{
public:
	void OpenStream(const std::string& filePath);
	void CloseStream();
	friend void operator<<(FileWriter& fw, const Puzzle& puzzle);
	friend void operator<<(FileWriter& fw, const std::string& string);
private:
	std::ofstream stream;
};