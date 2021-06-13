#include "BitConverter.h"
#include <iostream>
#include "ConsoleFunctions.h"

using namespace std;

void BitConverter::decimalToBinary(unsigned n)
{
    const int number_of_bits = 32;
    int binaryNum[number_of_bits];
 
    unsigned i = 0;
    while (n > 0) {
 
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (; i < number_of_bits; i++)
    {
        binaryNum[i] = 0;
    }

    cout << "0b";
    for (int j = number_of_bits - 1; j >= 0; j--)
        cout << binaryNum[j];
}

void BitConverter::decimalToBinaryExtra(unsigned n)
{
    const int number_of_bits = 32;
    cout << "0b";
    for (int i = number_of_bits - 1; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            cout << "1";
        else
            cout << "0";
    }
}

unsigned BitConverter::getNumber()
{
    unsigned i = 0;
    while (true)
    {
        cout << "Write A Positive Integer" << endl;
        cin >> i;
        CHECK_CONSOLE_ERROR()
        else
            return i;
    }
}

int BitConverter::run()
{
    auto n = getNumber();
    decimalToBinaryExtra(n);
    return 0;
}
