

#include <iostream>
#include <fstream>
#include <string>

#include "idvalidation.h"

#define INPUT_FILE_DELIMITER ','
int main()
{
    std::ifstream file;
    std::string line;
    std::size_t sum{ 0 };
    file.open("./quest_resources/ids.txt", std::ifstream::in);
    
    if (!file) 
    {
        std::cerr << "Can't open the source file!\n";
        return 1;
    }

    while (getline(file, line, INPUT_FILE_DELIMITER))
    {
        //std::cout << line << '\n';
        if (!line.empty()) 
        {
            auto it = convertID(line);
            sum += validate(it.first, it.second);
        }
    }
    std::cout << "Result is..." << sum << '\n';
    file.close();

  
    return 0;
}

