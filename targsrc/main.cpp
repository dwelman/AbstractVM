#include "Util.hpp"
#include "Parser.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <IOperand.hpp>
#include <OperandFactory.hpp>

std::ostream& operator<<(std::ostream& os, const IOperand* dt)
{
	os << dt->toString();
	return (os);
}

int main(int argc, char **argv)
{
    std::string     line;
    Parser          parser;
    OperandFactory	fac;
    bool            hitExit = false;

	if (argc > 1)
    {
        std::ifstream    file(argv[1]);
        if (file.is_open())
        {
            while (getline(file, line))
            {
                parser.ParseLine(line, hitExit);
            }
            parser.DumpOutput();
            file.close();
            if (hitExit != true)
            {
                try
                {
                    throw Parser::NoExitException();
                }
                catch(std::exception &e)
                {
                    std::cout << "Error: " << e.what() << std::endl;
                }
            }
        }
        else
        {
            std::cout << "File not found: " << argv[1] << std::endl;
            exit(-1);
        }
    }
    else
    {
        while (getline(std::cin, line))
        {
            line = Util::String::Trim(line, " \n\t");
            if (line == ";;")
            {
                parser.DumpOutput();
                if (hitExit != true)
                {
                    try
                    {
                        throw Parser::NoExitException();
                    }
                    catch(std::exception &e)
                    {
                        std::cout << "Error: " << e.what() << std::endl;
                    }
                }
                break;
            }
            parser.ParseLine(line, hitExit);
        }
    }
    return (0);
}