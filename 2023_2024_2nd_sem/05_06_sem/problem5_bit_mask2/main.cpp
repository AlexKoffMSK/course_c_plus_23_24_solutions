///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for a Problem: Bit Manipulation - Set Bit
/// \version    0.1.0
/// \date       22.01.2022
///
/// TASK DESCRIPTION
///
/// Write a program that takes an integer n and a position k as input. The program
/// should set (change to 1) the k-th bit of the integer n and print the resulting
/// number in binary and decimal forms.
///
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <bitset>

int main()
{
    unsigned int n;
    int k;
    std::cout << "Enter a number and a position to set: ";
    std::cin >> n >> k;

    n |= 1 << k;

    std::cout << "Binary: " << std::bitset<32>(n) << std::endl;

    std::cout << "Decimal: " << n << std::endl;

    return 0;
}
