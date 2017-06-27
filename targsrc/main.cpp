#include "Util.hpp"
#include "Parser.hpp"
#include <iostream>
#include <string>
#include <IOperand.hpp>
#include <OperandFactory.hpp>

int main(int argc, char **argv)
{
    std::string     line;
    Parser          parser;
    OperandFactory	fac;

	const IOperand	*op1 = fac.createOperand(TFLOAT, "10");
	const IOperand	*op2 = fac.createOperand(TINT32, "12");

	const IOperand	*op3 = *op1 * *op2;

	//std::cout << "le Val : " << *op3 << std::endl;

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