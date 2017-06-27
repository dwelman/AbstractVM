#include "Parser.hpp"
#include "Util.hpp"

#include <iostream>
#include <sstream>

Parser::Parser()
{
    operations["push"] = &Parser::push;
    operations["pop"] = &Parser::pop;
    operations["dump"] = &Parser::dump;
    operations["assert"] = &Parser::assert;
    operations["add"] = &Parser::add;
    operations["sub"] = &Parser::sub;
    operations["mul"] = &Parser::mul;
    operations["div"] = &Parser::div;
    operations["mod"] = &Parser::mod;
    operations["print"] = &Parser::print;
    operations["exit"] = &Parser::exit;
    line = 0;
}

Parser::~Parser()
{

}

bool Parser::ParseLine(const std::string &str)
{
    std::vector<std::string>    tokens = Util::String::Strsplit(str, " \t", false);

    line++;
    try
    {
        if (tokens.size() > 0)
        {
            if (tokens[0][0] != ';')
            {
                auto function = operations.find(tokens[0]);
                if (function != operations.end())
                {
                    if (tokens.size() > 1)
                    {
                        std::stringstream ss;
                        for (unsigned int k = 1; k < tokens.size(); k++)
                        {
                            ss << tokens[k];
                        }
                        value = ss.str();
                    }
                    (*this.*function->second)();
                }
                else
                {
                    throw UnknownInstructionException(tokens[0]);
                }
            }
        }
        return (true);
    }
    catch (std::exception &e)
    {
        std::cout << "Line " << line << " : Error : " << e.what() << std::endl;
        return (false);
    }
}

void Parser::push()
{
    if (value.empty())
    {
        throw SyntaxErrorException();
    }
    //Run some magic to turn value into an actual number
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
    //if (stack.size() > 0)
    {

    }
  //  else
    {
        throw AssertNotTrueException();
    }
}

void Parser::add()
{
    //if (stack.size() < 2)
    {
        throw NotEnoughValuesOnStackForOperationException();
    }
}

void Parser::sub()
{
    //if (stack.size() < 2)
    {
        throw NotEnoughValuesOnStackForOperationException();
    }
}

void Parser::mul()
{
    //if (stack.size() < 2)
    {
        throw NotEnoughValuesOnStackForOperationException();
    }
}

void Parser::div()
{
    //if (stack.size() < 2)
    {
        throw NotEnoughValuesOnStackForOperationException();
    }
}

void Parser::mod()
{
    //if (stack.size() < 2)
    {
        throw NotEnoughValuesOnStackForOperationException();
    }
}

void Parser::print()
{

}

void Parser::exit()
{
    //clear stack
    line = 0;
}

const char *Parser::SyntaxErrorException::what() const throw()
{
    return ("Syntax error");
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
