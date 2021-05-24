#include "Nim.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int Nim::run()
{
    bool players_turn = (rand() + 1) % 2 == 0;
    printNumberOfMatches();
    while (number_of_matches > 0)
    {
        players_turn = !players_turn;
        number_of_matches -= players_turn ? getPlayerNum() : getAiNumber();
        printNumberOfMatches();
    }
    cout << (players_turn ? "AI" : "You") << " Won";
    return 0;
}

Nim::Nim(int number_of_matches)
{
    this->number_of_matches = number_of_matches;
}

int Nim::getPlayerNum()
{
    int num;
    do
    {
        cout << "Pick a number to take between 1 - 3" << endl;
        cin >> num;  
    }
    while (num <= 0 || num > 3);
    return num;
}

void Nim::printNumberOfMatches()
{
    for (int i = 0; i < number_of_matches; i++)
    {
        cout << '|';
    }
    cout << endl;
}

int Nim::getAiNumber()
{
    auto aiMatches = rand() % 3 + 1;
    cout << "AI Takes " << aiMatches << " Number Of Matches" << endl;
    return aiMatches;
}