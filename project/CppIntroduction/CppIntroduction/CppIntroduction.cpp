#include "BitConverter.h"
#include "Nim.h"
#include "TicTacToe.h"

int main(int argc, char* argv[])
{
    auto nim = Nim(24);
    auto tic_tac_toe = TicTacToe();
    auto bit_converter = BitConverter();
    return bit_converter.run();
}
