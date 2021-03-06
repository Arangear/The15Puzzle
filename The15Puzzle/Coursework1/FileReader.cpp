//Author:        Daniel Cieslowski
//Date created:  16.10.2019
//Last modified: 22.10.2019
#include "FileReader.h"
#include <string>
#include <limits>

bool FileReader::openStream(const std::string filePath)
{
	stream.open(filePath, std::ios::in);
	return !stream.fail();
}

void FileReader::closeStream()
{
	stream.close();
}

result FileReader::loadPuzzles(const int count, std::deque<Puzzle>& puzzles)
{
	Puzzle puzzle;
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < puzzle.ElementCount(); j++)
		{
			stream >> puzzle(j);
			if (stream.fail())
			{
				stream.clear();
				return readFail;
			}
		}
		puzzles.insert(puzzles.end(), puzzle);
	}

	return success;
}

result FileReader::LoadPuzzles(const std::string filePath, std::deque<Puzzle>& puzzles)
{
	if (!openStream(filePath))
	{
		return openFail;
	}

	int count;
	stream >> count;
	if (stream.fail())
	{
		stream.clear();
		closeStream();
		return readFail;
	}

	result result = loadPuzzles(count, puzzles);
	closeStream();

	return result;
}