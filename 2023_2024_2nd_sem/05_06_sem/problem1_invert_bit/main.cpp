///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for a Problem: Bit Manipulation - Toggle Bit
/// \version    0.1.0
/// \date       24.01.2024
///
/// TASK DESCRIPTION
///
/// Write a program that takes an integer n and a position k as input. The program
/// should toggle (invert) the k-th bit of the integer n (i.e., change 0 to 1 and 
/// 1 to 0) and print the resulting number in binary and decimal forms.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <bitset>

int main()
{
    unsigned int n;
    int k;
    std::cout << "Enter a number and a position to toggle: ";
    std::cin >> n >> k;

    n ^= 1 << k;

    std::cout << "Binary: " << std::bitset<32>(n) << std::endl;

    std::cout << "Decimal: " << n << std::endl;

    return 0;
}

