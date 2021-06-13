#pragma once
#define CHECK_CONSOLE_ERROR() if (std::cin.fail()){std::cin.clear(); std::cin.ignore(numeric_limits<streamsize>::max(), '\n');}
namespace ConsoleFunctions
{
    void clear_console(char fill = ' ');
}