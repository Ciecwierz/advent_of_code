
#include <iostream>
#include <fstream>
#include <string>

#include "solution.h"
int main()
{

    std::ifstream file;
    std::string line;
    std::size_t sum{ 0 };
    file.open("./quest_resources/batteries.txt", std::ifstream::in);

    if (!file)
    {
        std::cerr << "Error while loading a file\n";
        return 1;
    }

    while (getline(file, line))
    {
        sum += getJoltage(std::move(line));
    }

    std::cout << "Joltage is equal to..." << sum << '\n';

    return 0;
}

