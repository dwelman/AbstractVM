#include "Util.hpp"

std::string Util::String::TrimLeft(const std::string & str, const std::string & trim)
{
    std::string			ret;
    unsigned long	    startpos;
    startpos = str.find_first_not_of(trim);

    if (std::string::npos != startpos)
    {
        ret = str.substr(startpos);
    }
    return (ret);
}

std::string Util::String::TrimRight(const std::string & str, const std::string & trim)
{
    std::string		ret;
    unsigned long	endpos;
    endpos = str.find_last_not_of(trim);

    if (std::string::npos != endpos)
    {
        ret = str.substr(0, endpos + 1);
    }
    return (ret);
}

std::string Util::String::Trim(const std::string & str, const std::string & trim)
{
    return (TrimLeft(TrimRight(str, trim), trim));
}

std::vector<std::string> Util::String::Strsplit(const std::string &str, std::string delim, bool useQuotes)
{
    std::vector<std::string> ret;
    int i = 0;
    int front = 0; //Used to track current string front
    bool foundQuotation = false; //Used to track if words are within quotes

    while (i < str.size())
    {
        if (str[i] == '"' && useQuotes)
        {
            foundQuotation = !foundQuotation;
        }
        for (int k = 0; k < delim.size(); k++)
        {
            if (str[i] == delim[k])
            {
                if (useQuotes && foundQuotation)
                {
                    i++;
                    continue;
                }
                if ((i - front) != 0)
                {
                    std::string temp = str.substr(front, i - front);
                    if (!temp.empty())
                    {
                        ret.push_back(temp);
                    }
                }
                front = i + 1;
            }
        }
        i++;
    }
    std::string temp = str.substr(front, i - front);
    if (!temp.empty())
    {
        ret.push_back(str.substr(front, i - front));
    }
    return (ret);
}
