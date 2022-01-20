#ifndef _STRING_SPLIT
#define _STRING_SPLIT

#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> split(const std::string &s, const std::string &delimiters = " ")
{
    std::vector<std::string> tokens;
    // find the first fragment of the string
    // string::size_type : loacation of some char in the string
    std::string::size_type lastPos = s.find_first_not_of(delimiters, 0);
    std::string::size_type pos = s.find_first_of(delimiters, lastPos);
    try
    {
        if (pos == std::string::npos)
            throw 99;
    }
    catch (int x)
    {
        std::cerr << "Can't find any fragment! Please check the delimeters\n";
        return tokens;
    }
    // string::npos : end location of string
    while (pos != std::string::npos || lastPos != std::string::npos)  
    {
        // put the fragment into vector
        tokens.push_back(s.substr(lastPos, pos - lastPos));
        // find next fragment of the string
        lastPos = s.find_first_not_of(delimiters, pos);
        pos = s.find_first_of(delimiters, lastPos);
    }
    return tokens;
}
#endif

