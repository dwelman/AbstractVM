#include "Parser.hpp"
#include "Util.hpp"

#include <iostream>
#include <sstream>

Parser::Parser()
{

}

Parser::~Parser()
{

}

bool Parser::ParseLine(const std::string &str)
{
    std::vector<std::string>    tokens = Util::String::Strsplit(str, " \n\t", false);
    if (tokens.size() > 0)
    {
        if (tokens[0][0] != ';')
        {

        }
    }
    return (true);
}

void Parser::push()
{

}

void Parser::pop()
{
    //if (stack.size() == 0)
    {
        throw EmptyStackPopException();
    }
}

void Parser::dump()
{

}

void Parser::assert()
{

}

void Parser::add()
{

}

void Parser::sub()
{

}

void Parser::mul()
{

}

void Parser::div()
{

}

void Parser::mod()
{

}

void Parser::print()
{

}

void Parser::exit()
{

}

Parser::SyntaxErrorException::SyntaxErrorException(int l) : line(l)
{
}

const char *Parser::SyntaxErrorException::what() const throw()
{
    std::stringstream ss;
    ss << "Syntax error: Line " << line;
    return (ss.str().c_str());
}

Parser::UnknownInstructionException::UnknownInstructionException(std::string const &e) : instruction(e)
{
}

const char *Parser::UnknownInstructionException::what() const throw()
{
    std::string ret;

    ret = "Unknown instruction: " + instruction;
    return (ret.c_str());
}

const char *Parser::ValueOverflowException::what() const throw()
{
    return ("Value overflow");
}

const char *Parser::ValueUnderflowException::what() const throw()
{
    return ("Value underflow");
}

const char *Parser::EmptyStackPopException::what() const throw()
{
    return ("Cannot call 'pop' on an empty stack");
}

const char *Parser::DivisionByZeroException::what() const throw()
{
    return ("Division by zero");
}

const char *Parser::NoExitException::what() const throw()
{
    return ("Program does not have an exit");
}

const char *Parser::AssertNotTrueException::what() const throw()
{
    return ("Assert is false");
}

const char *Parser::NotEnoughValuesOnStackForOperationException::what() const throw()
{
    return ("Not enough values on stack to call operation");
}
