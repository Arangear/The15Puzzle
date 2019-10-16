#include "FileReader.h"
//Author:        Daniel Cieslowski
//Date created:  16.10.2019
//Last modified: 16.10.2019

void FileReader::OpenStream(std::string filePath)
{
	stream.open(filePath, std::ios::in);
}

void FileReader::CloseStream()
{
	stream.close();
}
