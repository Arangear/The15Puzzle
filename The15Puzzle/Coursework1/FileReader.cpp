#include "FileReader.h"
//Author:        Daniel Cieslowski
//Date created:  16.10.2019
//Last modified: 17.10.2019

void FileReader::OpenStream(const std::string& filePath)
{
	stream.open(filePath, std::ios::in);
}

void FileReader::CloseStream()
{
	stream.close();
}

void operator>>(FileReader& fileReader, Puzzle& puzzle)
{
	for (int i = 0; i < puzzle.GetSize(); i++)
	{
		for (int j = 0; j < puzzle.GetSize(); j++)
		{
			fileReader.stream >> puzzle(i, j);
		}
	}
}
