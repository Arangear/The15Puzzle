//Author:        Daniel Cieslowski
//Date created:  23.10.2019
//Last modified: 24.10.2019
#include "FileWriter.h"

result FileWriter::WritePuzzlesToFile(const std::string filePath, const std::deque<Puzzle>& puzzles)
{
	if (!openStream(filePath))
	{
		return openFail;
	}
	stream << puzzles.size() << "\n";
	for (unsigned int i = 0; i < puzzles.size() - 1; i++)
	{
		stream << puzzles[i];
		stream << "\n\n";
	}
	stream << puzzles[puzzles.size() - 1];
	closeStream();
	return success;
}

result FileWriter::WriteSolutionsToFile(const std::string filePath, std::deque<Puzzle>& puzzles)
{
	if (!openStream(filePath))
	{
		return openFail;
	}
	stream << puzzles.size() << "\n";
	for (unsigned int i = 0; i < puzzles.size() - 1; i++)
	{
		stream << puzzles[i] << "\n";
		stream << "row = " << puzzles[i].GetSolution().rows << "\n";
		stream << "column = " << puzzles[i].GetSolution().columns << "\n";
		stream << "reverse row = " << puzzles[i].GetSolution().reversedRows << "\n";
		stream << "reverse column = " << puzzles[i].GetSolution().reversedColumns << "\n\n";
		if (puzzles[i].IsPartiallySolved())
		{
			stream << "(total for row & column, including reverse, in this configuration)\n";
			for (int i = 0; i < puzzles[i].Size() - 1; i++)
			{
				stream << i + 2 << " = " << puzzles[i].GetPartialSolution(false, i + 2) << "\n";
			}
		}
		if (puzzles[i].IsPartiallySolvedAllTurns())
		{
			stream << "(total for row and column, including reverse, for all valid turns)\n";
			for (int i = 0; i < puzzles[i].Size() - 1; i++)
			{
				stream << i + 2 << " = " << puzzles[i].GetPartialSolution(true, i + 2) << "\n";
			}
		}
		stream << "\n";
	}
	stream << puzzles[puzzles.size() - 1] << "\n";
	stream << "row = " << puzzles[puzzles.size() - 1].GetSolution().rows << "\n";
	stream << "column = " << puzzles[puzzles.size() - 1].GetSolution().columns << "\n";
	stream << "reverse row = " << puzzles[puzzles.size() - 1].GetSolution().reversedRows << "\n";
	stream << "reverse column = " << puzzles[puzzles.size() - 1].GetSolution().reversedColumns;
	if (puzzles[puzzles.size() - 1].IsPartiallySolved())
	{
		stream << "(total for row & column, including reverse, in this configuration)\n";
		for (int i = 0; i < puzzles[puzzles.size() - 1].Size() - 1; i++)
		{
			stream << i + 2 << " = " << puzzles[puzzles.size() - 1].GetPartialSolution(false, i + 2) << "\n";
		}
	}
	if (puzzles[puzzles.size() - 1].IsPartiallySolvedAllTurns())
	{
		stream << "(total for row and column, including reverse, for all valid turns)\n";
		for (int i = 0; i < puzzles[puzzles.size() - 1].Size() - 1; i++)
		{
			stream << i + 2 << " = " << puzzles[puzzles.size() - 1].GetPartialSolution(true, i + 2) << "\n";
		}
	}
	closeStream();
	return success;
}

bool FileWriter::openStream(const std::string filePath)
{
	stream.open(filePath, std::ios::out | std::ios::trunc);
	return !stream.fail();
}

void FileWriter::closeStream()
{
	stream.close();
}

void operator<<(FileWriter& fw, const Puzzle& puzzle)
{
	fw.stream << puzzle;
}

void operator<<(FileWriter& fw, const std::string message)
{
	fw.stream << message;
}

void operator<<(FileWriter& fw, const int number)
{
	fw.stream << number << "\n";
}
