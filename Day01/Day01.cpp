

#include <iostream>
#include <fstream>
#include <string>
#include "Dial.h"

int main()
{
    constexpr auto startNum{ 50 };
    Dial safe(startNum);
    Instruction sequence;
    std::ifstream fileIn;
    std::string line;
    fileIn.open("./quest_resources/rotations.txt", std::ifstream::in);

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

