//Author:        Daniel Cieslowski
//Date created:  23.10.2019
//Last modified: 23.10.2019
#pragma once

#include <fstream>

enum result { success, openFail, readFail, writeFail };

//Abstract class for managing file input and output.
class FileManager
{
private:
	virtual bool openStream(const std::string filePath) = 0;
	virtual void closeStream() = 0;
};