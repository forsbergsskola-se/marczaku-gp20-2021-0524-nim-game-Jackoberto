#pragma once
#include <sstream>
#include <string>

using namespace std;

namespace CodingChallenges
{
    inline bool endsWith(string const& str, string const& ending)
    {
        if (ending.length() > str.length())
            return false;
        auto diff = str.length() - ending.length();
        for (auto i = diff; i < str.length(); i++)
        {
            if (str[i] != ending[i - diff])
                return false;
        }
        return true;
    }

    inline int digitalRoot(int n)
    {
        string str = to_string(n);
        int* ints = new int[n];
        for (int i = 0; i < str.length(); i++)
        {
            stringstream stream;
    
            stream << str[i];
            stream >> ints[i];
        }
        int result = 0;
        for (int i = 0; i < str.length(); i++)
        {
            result += ints[i];
        }
        if (result < 10)
           return result;
        return digitalRoot(result);
    }
}