#include "FileWriter.h"
//Author:        Daniel Cieslowski
//Date created:  16.10.2019
//Last modified: 17.10.2019

void FileWriter::OpenStream(const std::string& filePath)
{
	stream.open(filePath, std::ios::out | std::ios::trunc);
}

void FileWriter::CloseStream()
{
	stream.close();
}

void operator<<(FileWriter& fw, const Puzzle& puzzle)
{
	fw.stream << puzzle;
}

void operator<<(FileWriter& fw, const std::string& string)
{
	fw.stream << string;
}
