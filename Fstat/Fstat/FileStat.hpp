#pragma once

#include <iostream>
#include <string>

class FileStat
{
private:
	std::string filePath;
	std::string fileContent;
	int numberOfChars;
	int numberOfLines;
	int numberOfSpaces;

public:
	FileStat(std::string* filename);
	~FileStat();
	std::string ReadAllFile();
	int getNumberOfChars();
	void PrintStats();
};

