#include "Util.hpp"
#include "Parser.hpp"
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    std::string     line;
    Parser          parser;

    if (argc > 1)
    {

    }
    else
    {
        while (getline(std::cin, line))
        {
            line = Util::String::Trim(line, " \n\t");
            if (line == ";;")
            {
                break;
            }
            if (parser.ParseLine(line) == false)
            {
                break;
            }
        }
    }
    return (0);
}