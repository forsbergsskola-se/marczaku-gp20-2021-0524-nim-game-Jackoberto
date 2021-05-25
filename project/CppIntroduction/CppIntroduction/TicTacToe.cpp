#include "TicTacToe.h"
#include <iostream>

#include "ConsoleFunctions.h"
using namespace std;

int TicTacToe::run()
{
    cout << "Do you wanna play multiplayer? y/n" << endl;
    string s = "";
    while (s != "y" && s != "n")
    {
        cin >> s;   
    }
    const bool withAI = s == "y" ? false : true;
    ticTacToeTwoPlayer();
    return 0;
}

void TicTacToe::getPlayerInput(bool players_turn)
{
    while (true)
    {
        int row;
        int column;
        cin >> row >> column;
        CHECK_CONSOLE_ERROR()
        else if (row >= 0 && row <= 2 && column >= 0 && column <= 2)
        {
            if (board[row][column] != 0)
            {
                cout << "Position Is Already Occupied; please re-enter." << endl;
                continue;
            }
            board[row][column] = players_turn ? 1 : 2;
            return;
        }
        else
        {
            cout << "Invalid input; please re-enter." << endl;
        }
    }
}

int TicTacToe::checkWinCondition()
{
    return 0;
}

void TicTacToe::ticTacToeTwoPlayer()
{
    bool players_turn = (rand() + 1) % 2 == 0;
    displayBoard();
    while (checkWinCondition() == 0)
    {
        players_turn = !players_turn;
        getPlayerInput(players_turn);
        displayBoard();
    }
}

void TicTacToe::ticTacToeAI()
{

}

void TicTacToe::displayBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j];
            if (j != 2)
                cout << "|";
            else
                cout << endl;
        }
    }
}