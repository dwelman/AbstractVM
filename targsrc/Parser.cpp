#include "Parser.hpp"
#include "Util.hpp"

#include <iostream>

Parser::Parser()
{

}

Parser::~Parser()
{

}

bool Parser::ParseLine(const std::string &str)
{
    std::vector<std::string>    tokens = Util::String::Strsplit(str, " \n\t", false);
    for (unsigned int i = 0; i < tokens.size(); i++)
    {
        std::cout << tokens[i] << std::endl;
    }
    return (true);
}

void Parser::push()
{

}

void Parser::pop()
{

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
