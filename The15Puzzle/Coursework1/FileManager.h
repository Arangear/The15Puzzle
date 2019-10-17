//Author:        Daniel Cieslowski
//Date created:  16.10.2019
//Last modified: 16.10.2019
#pragma once

#include <fstream>

class FileManager
{
public:
	virtual void OpenStream(const std::string& filePath) = 0;
	virtual void CloseStream() = 0;
};