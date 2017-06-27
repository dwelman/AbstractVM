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
    std::string value;

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

    unsigned int line;
public:
    class SyntaxErrorException : public std::exception
    {
    public:
        virtual const char  *what() const throw();
    };

    class UnknownInstructionException : public std::exception
    {
    private:
        std::string instruction;
    public:
        UnknownInstructionException(std::string const &i);
        virtual const char  *what() const throw();
    };

    class ValueOverflowException : public std::exception
    {
    public:
        virtual const char  *what() const throw();
    };

    class ValueUnderflowException : public std::exception
    {
    public:
        virtual const char  *what() const throw();
    };

    class EmptyStackPopException : public std::exception
    {
    public:
        virtual const char  *what() const throw();
    };

    class DivisionByZeroException : public std::exception
    {
    public:
        virtual const char  *what() const throw();
    };

    class NoExitException : public std::exception
    {
    public:
        virtual const char  *what() const throw();
    };

    class AssertNotTrueException : public std::exception
    {
    public:
        virtual const char  *what() const throw();
    };

    class NotEnoughValuesOnStackForOperationException : public std::exception
    {
    public:
        virtual const char  *what() const throw();
    };

    Parser();
    ~Parser();
    bool    ParseLine(const std::string &str);
};