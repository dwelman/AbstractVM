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

	const IOperand	*op1 = fac.createOperand(TINT32, "12");
	const IOperand	*op2 = fac.createOperand(TINT32, "10");

	const IOperand	*op3 = *op1 % *op2;

	std::cout << "le Val : " << op3 << std::endl;

	if (argc > 1)
    {
        std::ifstream    file(argv[1]);
        if (file.is_open())
        {
            while (getline(file, line))
            {
                if (parser.ParseLine(line) == false)
                {
                    hitExit = true;
                }
                else
                {
                    hitExit = false;
                }
            }
            file.close();
            if (hitExit != true)
            {
                try
                {
                    throw Parser::NoExitException();
                }
                catch(std::exception &e)
                {
                    std::cout << e.what() << std::endl;
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
                if (hitExit != true)
                {
                    try
                    {
                        throw Parser::NoExitException();
                    }
                    catch(std::exception &e)
                    {
                        std::cout << e.what() << std::endl;
                    }
                }
                break;
            }
            if (parser.ParseLine(line) == false)
            {
                hitExit = true;
            }
            else
            {
                hitExit = false;
            }
        }
    }
    return (0);
}