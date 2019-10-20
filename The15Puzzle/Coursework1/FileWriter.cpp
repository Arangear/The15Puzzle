//Author:        Daniel Cieslowski
//Date created:  16.10.2019
//Last modified: 20.10.2019
#include "FileWriter.h"

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
	stream.open(filePath, std::ios::out | std::ios::trunc);
	stream << puzzles.size() << "\n";
	for (int i = 0; i < puzzles.size() - 1; i++)
	{
		stream << puzzles[i] << "\n";
		stream << "row " << puzzles[i].GetSolution().rows << "\n";
		stream << "column " << puzzles[i].GetSolution().columns << "\n";
		stream << "reverse row " << puzzles[i].GetSolution().reversedRows << "\n";
		stream << "reverse column " << puzzles[i].GetSolution().reversedColumns << "\n\n";
	}
	stream << puzzles[puzzles.size() - 1] << "\n";
	stream << "row " << puzzles[puzzles.size() - 1].GetSolution().rows << "\n";
	stream << "column " << puzzles[puzzles.size() - 1].GetSolution().columns << "\n";
	stream << "reverse row " << puzzles[puzzles.size() - 1].GetSolution().reversedRows << "\n";
	stream << "reverse column " << puzzles[puzzles.size() - 1].GetSolution().reversedColumns;
	stream.close();
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
