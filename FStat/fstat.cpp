/*
 * Name        : FStat
 * Author      : Arthur Pons aka Unguest
 * Description : A simple program that gives basic stats about a file
 * Date        : 23/03/20
 */

#include <iostream>
#include "filestats.hpp"
int main(int argc, char** argv) {

    if (argc < 2) {
        std::cout << "Usage : " << argv[0] << " <filename>" << std::endl;
        exit(0);
    }

    getStats(argv[1]);


    return EXIT_SUCCESS;
}