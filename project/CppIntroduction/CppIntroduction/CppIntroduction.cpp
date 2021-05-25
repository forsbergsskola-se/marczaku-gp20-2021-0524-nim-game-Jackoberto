#include "Nim.h"
#include "TicTacToe.h"

int main(int argc, char* argv[])
{
    auto nim = Nim(24);
    auto ticTacToe = TicTacToe();
    return ticTacToe.run();
}
