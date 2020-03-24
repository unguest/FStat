#include "filestats.hpp"

void getStats(std::string filename)
{
	std::ifstream fileReader(filename);
	std::string line;

	int lineBuf = 0 , spaceBuf = 0, wordBuf = 0, charBuf = 0;
	while (std::getline(fileReader, line))
	{
		lineBuf++;
		for (char c : line) {
			if (c == ' ') {
				spaceBuf++;
				wordBuf++;
			}
			else if (c != '\n' && c != '\r') {
				charBuf++;
			}
		}
	}
	std::cout << "Lines : " << lineBuf << std::endl;
	std::cout << "Characters : " << charBuf << std::endl;
	std::cout << "Words : " << wordBuf << std::endl;
	std::cout << "Spaces : " << spaceBuf << std::endl;

}
