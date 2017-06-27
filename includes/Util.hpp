#pragma once

#include <string>
#include <vector>

class Util
{
public:
    class String
    {
    public:
        static std::string TrimLeft(const std::string &str, const std::string &trim);
        static std::string TrimRight(const std::string &str, const std::string &trim);
        static std::string Trim(const std::string &str, const std::string &trim);
        static std::vector<std::string> Strsplit(const std::string &str, std::string delim, bool useQuotes);
    };
};
