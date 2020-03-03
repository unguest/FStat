#include "FileStat.hpp"
#include <vector>
#include <string>
#include <numeric>
#include <iostream>
#include <fstream>
#include <algorithm>

FileStat::FileStat(std::string* filename) {
	filePath = *filename;
	fileContent = ReadAllFile();
	numberOfChars = getNumberOfChars();
	numberOfSpaces = std::count(std::begin(fileContent), std::end(fileContent), ' ');
	numberOfLines = std::count(std::begin(fileContent), std::end(fileContent), '\n');
}

FileStat::~FileStat() { // Be sure to free every exploited memory region
	free(&filePath);
	free(&numberOfChars);
	free(&numberOfSpaces);
	free(&numberOfLines);
}

std::string FileStat::ReadAllFile() {
	std::ifstream fileReader =  std::ifstream(this->filePath);
	std::string tmpStr;
	std::vector<std::string> fileLines;

	while (std::getline(fileReader, tmpStr)) {
		fileLines.push_back(tmpStr);
		tmpStr = "";
	}
	fileReader.close();
	return std::accumulate(fileLines.begin(), fileLines.end(), std::string(""));
}

int FileStat::getNumberOfChars() {
	int chars{ 0 };
	for(char c : this-> fileContent) {
		chars++;
	}
	return chars;
}

void FileStat::PrintStats() {
	std::cout << "The file " << this->filePath << "contains : \n";
	std::cout << this->numberOfLines << " lines\n";
	std::cout << this->numberOfChars << " characters\n";
	std::cout << this->numberOfSpaces << " spaces\n";
}
