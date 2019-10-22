//Author:        Daniel Cieslowski
//Date created:  16.10.2019
//Last modified: 22.10.2019
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