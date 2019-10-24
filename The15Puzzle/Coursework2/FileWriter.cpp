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
		writeSolutionToFile(puzzles[i]);
		stream << "\n";
	}
	writeSolutionToFile(puzzles[puzzles.size() - 1]);
	return success;
}

void FileWriter::writeSolutionToFile(Puzzle& puzzle)
{
	stream << puzzle << "\n";
	stream << "row = " << puzzle.GetSolution().rows << "\n";
	stream << "column = " << puzzle.GetSolution().columns << "\n";
	stream << "reverse row = " << puzzle.GetSolution().reversedRows << "\n";
	stream << "reverse column = " << puzzle.GetSolution().reversedColumns << "\n\n";
	if (puzzle.IsPartiallySolved())
	{
		stream << "(total for row & column, including reverse, in this configuration)\n";
		for (int i = 0; i < puzzle.Size() - 1; i++)
		{
			stream << i + 2 << " = " << puzzle.GetPartialSolution(false, i + 2) << "\n";
		}
	}
	if (puzzle.IsPartiallySolvedAllTurns())
	{
		stream << "(total for row and column, including reverse, for all valid turns)\n";
		for (int i = 0; i < puzzle.Size() - 1; i++)
		{
			stream << i + 2 << " = " << puzzle.GetPartialSolution(true, i + 2) << "\n";
		}
	}
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
