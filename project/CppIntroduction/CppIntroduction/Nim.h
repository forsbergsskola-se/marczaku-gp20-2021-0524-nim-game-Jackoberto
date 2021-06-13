#pragma once

class Nim
{
    int getPlayerNum();
    void printNumberOfMatches();
    int getAiNumber();
    int number_of_matches;
    void nimAI();
    void nimTwoPlayers();
public:
    explicit Nim(int number_of_matches);
    int run();
};
