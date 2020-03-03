#include <iostream>
#include <string>

#include "FileStat.hpp"

int main(int argc, char** argv)
{
	if (argc < 2) {
		std::cout << "Usage : "<< argv[0] << " <file_path>" <<"\n";
		return EXIT_SUCCESS;
	}

	FileStat fst = FileStat((std::string *) argv[1]);
	fst.PrintStats();
	return EXIT_SUCCESS;
}
