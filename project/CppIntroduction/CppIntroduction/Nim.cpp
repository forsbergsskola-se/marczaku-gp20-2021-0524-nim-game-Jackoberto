#include "Nim.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include "ConsoleFunctions.h"

using namespace std;

int Nim::run()
{
    cout << "Do you wanna play multiplayer? y/n" << endl;
    string s = "";
    while (s != "y" && s != "n")
    {
        cin >> s;   
    }
    const bool withAI = s == "y" ? false : true; 
    if (withAI)
        nimAI();
    else
        nimTwoPlayers();
    return 0;
}

Nim::Nim(int number_of_matches)
{
    this->number_of_matches = number_of_matches;
}

int Nim::getPlayerNum()
{
    int num;
    int max = number_of_matches > 2 ? 3 : number_of_matches;
    do
    {
        cout << "Pick a number to take between 1 - " << max << endl;
        cin >> num;
        if (num > 0 && num <= max)
        {
            return num;
        }
        CHECK_CONSOLE_ERROR()
        cout << "Invalid input; please re-enter." << endl;
    }
    while (true);
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
    int aiMatches;
    switch (number_of_matches)
    {
        case 1:
            aiMatches = 1;
            break;
        case 2:
            aiMatches = 1;
            break;
        case 3:
            aiMatches = 2;
            break;
        case 4:
            aiMatches = 3;
            break;
        case 6:
            aiMatches = 1;
            break;
        case 7:
            aiMatches = 2;
            break;
        case 8:
            aiMatches = 3;
            break;
        default:
            aiMatches = rand() % 3 + 1;
    }
    cout << "AI Takes " << aiMatches << " Number Of Matches" << endl;
    return aiMatches;
}

void Nim::nimAI()
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
}

void Nim::nimTwoPlayers()
{
    bool players_turn = (rand() + 1) % 2 == 0;
    printNumberOfMatches();
    while (number_of_matches > 0)
    {
        players_turn = !players_turn;
        cout << (players_turn ? "Player 1" : "Player 2") << endl;
        number_of_matches -= getPlayerNum();
        printNumberOfMatches();
    }
    cout << (players_turn ? "Player 2" : "Player 1") << " Won";
}
