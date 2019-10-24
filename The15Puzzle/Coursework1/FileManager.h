//Author:        Daniel Cieslowski
//Date created:  16.10.2019
//Last modified: 24.10.2019
#pragma once
#include <fstream>

//Enum indicating the result of operations.
enum result { success, openFail, readFail, writeFail };

//Abstract class for managing file input and output.
class FileManager
{
private:
	//Opens the stream to the file indicated by filePath.
	//Returns whether it was successful or not.
	virtual bool openStream(const std::string filePath) = 0;
	//Closes the open stream.
	virtual void closeStream() = 0;
};