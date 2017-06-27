#pragma once

#include <string>
#include <deque>
#include <map>

class Parser
{
private:
    Parser(Parser const &p);
    Parser operator=(Parser const &p);

    typedef void (Parser::*operation)();
    std::map<std::string, Parser::operation> operations;

    void push();
    void pop();
    void dump();
    void assert();
    void add();
    void sub();
    void mul();
    void div();
    void mod();
    void print();
    void exit();
public:
    Parser();
    ~Parser();
    bool    ParseLine(const std::string &str);
};