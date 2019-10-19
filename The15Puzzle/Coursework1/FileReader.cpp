//Author:        Daniel Cieslowski
//Date created:  16.10.2019
//Last modified: 19.10.2019
#include "FileReader.h"
#include <string>
#include <limits>

void FileReader::OpenStream(const std::string& filePath)
{
	stream.open(filePath, std::ios::in);
}

void FileReader::CloseStream()
{
	stream.close();
}

void FileReader::LoadPuzzles(const std::string& filePath, std::deque<Puzzle>& puzzles)
{
	stream.open(filePath);
	if (stream.fail())
	{
		std::cerr << "Failed to open file " << filePath << "\n";
		return;
	}

	int count;
	stream >> count;
	if (stream.fail())
	{
		dataFormatError();
		return;
	}

	Puzzle puzzle;

	for (int i = 0; i < count; i++)
	{
		stream >> puzzle;
		puzzles.insert(puzzles.end(), puzzle);
	}

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

void FileReader::dataFormatError()
{
	std::cerr << "Data format in file incorrect.\n";
	stream.clear();
	stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}