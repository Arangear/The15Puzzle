//Author:        Daniel Cieslowski
//Date created:  16.10.2019
//Last modified: 20.10.2019
#include "FileReader.h"
#include <string>
#include <limits>

void FileReader::openStream(const std::string& filePath)
{
	stream.open(filePath, std::ios::in);
}

void FileReader::closeStream()
{
	stream.close();
}

void FileReader::loadPuzzles(const int& count, std::deque<Puzzle>& puzzles)
{
	Puzzle puzzle;
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < puzzle.GetSize() - 1; j++)
		{
			for (int k = 0; k < puzzle.GetSize(); k++)
			{
				stream >> puzzle(j, k);
				if (stream.fail())
				{
					dataFormatError();
					return;
				}
			}
		}
		for (int k = 0; k < puzzle.GetSize() - 1; k++)
		{
			stream >> puzzle(puzzle.GetSize() - 1, k);
			if (stream.fail())
			{
				dataFormatError();
				return;
			}
		}
		puzzles.insert(puzzles.end(), puzzle);
	}
}

void FileReader::LoadPuzzles(const std::string& filePath, std::deque<Puzzle>& puzzles)
{
	openStream(filePath);

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
		stream.close();
		return;
	}

	loadPuzzles(count, puzzles);
	closeStream();
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