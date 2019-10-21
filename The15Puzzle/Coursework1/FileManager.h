//Author:        Daniel Cieslowski
//Date created:  16.10.2019
//Last modified: 21.10.2019
#pragma once

#include <fstream>

class FileManager
{
private:
	virtual void openStream(const std::string filePath) = 0;
	virtual void closeStream() = 0;
};