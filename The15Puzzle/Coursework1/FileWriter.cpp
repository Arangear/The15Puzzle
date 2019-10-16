#include "FileWriter.h"
//Author:        Daniel Cieslowski
//Date created:  16.10.2019
//Last modified: 16.10.2019

void FileWriter::OpenStream(std::string filePath)
{
	stream.open(filePath, std::ios::out | std::ios::trunc);
}

void FileWriter::CloseStream()
{
	stream.close();
}
