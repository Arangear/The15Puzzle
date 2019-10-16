//Author:        Daniel Cieslowski
//Date created:  16.10.2019
//Last modified: 16.10.2019
#pragma once
#include "FileManager.h"

class FileReader : public FileManager
{
public:
	void OpenStream(std::string filePath);
	void CloseStream();
private:
	std::ifstream stream;
};