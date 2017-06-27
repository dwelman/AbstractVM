#include "Util.hpp"
#include "Parser.hpp"
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    std::string     line;

    if (argc > 1)
    {

    }
    else
    {
        while (getline(std::cin, line))
        {
            std::cout << line << std::endl;
            line = Util::String::Trim(line, " \n\t");
            if (line == ";;")
            {
                exit(-1);
            }
        }
    }
    return (0);
}