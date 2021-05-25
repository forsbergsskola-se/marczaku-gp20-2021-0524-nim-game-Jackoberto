#pragma once

class TicTacToe
{
    int board[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
public:
    int run();
    void getPlayerInput(bool players_turn);
    int checkWinCondition();
    void ticTacToeTwoPlayer();
    void getAIInput();
    void ticTacToeAI();
    void displayBoard();
};
