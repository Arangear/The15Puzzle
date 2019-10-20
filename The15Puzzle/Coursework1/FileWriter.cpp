#include "FileWriter.h"
//Author:        Daniel Cieslowski
//Date created:  16.10.2019
//Last modified: 18.10.2019

void FileWriter::WritePuzzlesToFile(const char* filePath, std::deque<Puzzle>& puzzles)
{
	stream.open(filePath, std::ios::out | std::ios::trunc);
	stream << puzzles.size() << "\n";
	for (int i = 0; i < puzzles.size() - 1; i++)
	{
		stream << puzzles[i];
		stream << "\n\n";
	}
	stream << puzzles[puzzles.size() - 1];
	stream.close();
}

void FileWriter::WriteSolutionsToFile(const std::string & filePath, std::deque<Puzzle>& puzzles)
{
	stream << puzzles.size() << "\n";
	for (Puzzle& puzzle : puzzles)
	{
		stream << puzzle << "\n";
		stream << "row " << puzzle.GetSolution().rows << "\n";
		stream << "column " << puzzle.GetSolution().columns << "\n";
		stream << "reverse row " << puzzle.GetSolution().reversedRows << "\n";
		stream << "reverse column " << puzzle.GetSolution().reversedColumns << "\n\n";
	}
}

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

void operator<<(FileWriter& fw, const char* string)
{
	fw.stream << string;
}

void operator<<(FileWriter & fw, const int & number)
{
	fw.stream << number << "\n";
}
