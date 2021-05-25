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
    if (withAI)
        ticTacToeAI();
    else
       ticTacToeTwoPlayer();
    return 0;
}

void TicTacToe::getPlayerInput(bool players_turn)
{
    while (true)
    {
        int row;
        int column;
        cout << "Type a coordinate formatted {row} {column}" << endl;
        cin >> row >> column;
        CHECK_CONSOLE_ERROR()
        else if (row >= 1 && row <= 3 && column >= 1 && column <= 3)
        {
            row -= 1;
            column -= 1;
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

void TicTacToe::getAIInput()
{
    while (true)
    {
        int row;
        int column;
        row = rand() % 3;
        column = rand() % 3;
        if (row >= 0 && row <= 2 && column >= 0 && column <= 2)
        {
            if (board[row][column] != 0)
            {
                continue;
            }
            board[row][column] = 2;
            return;
        }
    }
}

int TicTacToe::checkWinCondition()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] != board[i][1] || board[i][1] != board[i][2]) 
            continue;
        if (board[i][0] != 0)
            return board[i][ 0];
    }
        
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] != board[1][i] || board[1][i] != board[2][i]) 
            continue;
        if (board[0][i] != 0)
            return board[i][0];
    }
        
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) 
        if (board[1][1] != 0)
            return board[1][1];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) 
        if (board[1][1] != 0)
            return board[1][1];
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == 0)
                return 0;
        }
    }
        
    return -1;
}

void TicTacToe::ticTacToeTwoPlayer()
{
    bool players_turn = false;
    displayBoard();
    int winner = 0;
    while (winner == 0)
    {
        players_turn = !players_turn;
        cout << "Player " << (players_turn ? 1 : 2) << endl;
        getPlayerInput(players_turn);
        displayBoard();
        winner = checkWinCondition();
    }
    if (winner == -1)
        cout << "It's a draw";
    cout << "Winner is Player " << winner;
}

void TicTacToe::ticTacToeAI()
{
    bool players_turn = false;
    displayBoard();
    int winner = 0;
    while (winner == 0)
    {
        players_turn = !players_turn;
        cout << (players_turn ? "Players" : "AIs") << " Turn" << endl;
        if (players_turn)
            getPlayerInput(players_turn);
        else
            getAIInput();
        displayBoard();
        winner = checkWinCondition();
    }
    if (winner == -1)
        cout << "It's a draw";
    cout << (winner == 1 ? "You" : "AI") << " Won";
}

void TicTacToe::displayBoard()
{
    cout << "  " << "1|2|3" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j == 0)
                cout << i + 1 << "|";
            cout << board[i][j];
            if (j != 2)
                cout << "|";
            else
                cout << endl;
        }
    }
}