#pragma once
#include <xstring>

class Nim
{
    int getPlayerNum();
    void printNumberOfMatches();
    int getAiNumber();
    int number_of_matches;
public:
    explicit Nim(int number_of_matches);
    int run();
};
