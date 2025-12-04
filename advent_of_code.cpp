

#include <iostream>
#include <fstream>
#include <string>
#include "./Day 01/Dial.h"

int main()
{
    constexpr auto startNum{ 50 };
    Dial safe(startNum);
    Instruction sequence;
    std::ifstream fileIn;
    std::string line;
    fileIn.open("./Day 01/quest_resources/rotations.txt", std::ifstream::in);

    if(fileIn.is_open())
    {
        while (getline(fileIn, line))
        {
            sequence.set(line);
            safe.rotate(sequence);
        }
    }
    std::cout << "Password is..." << safe.getPassword() << '\n';
}

