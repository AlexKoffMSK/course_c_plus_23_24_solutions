////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem 7: "Multiplication Table".
/// \author     Sergey Shershakov
/// \version    0.1.0
/// \date       19.01.2021
///             This code is for educational purposes of the course "Introduction
///             to programming" provided by the Faculty of Computer Science
///             at the Higher School of Economics.
///
/// Program asks a user for two numbers, 1 <= (m, n) <= 8 and prints a rectangle
/// multiplication table aligning output at tab positions.
///
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip> 

int main()
{
    int m, n;
    std::cout << "Enter two numbers between 1 and 8: ";
    std::cin >> m >> n;

    if (m < 1 || m > 8 || n < 1 || n > 8) {
        std::cout << "Numbers must be between 1 and 8." << std::endl;
        return 1; 
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            std::cout << std::setw(4) << i * j;
        }
        std::cout << std::endl;
    }

    return 0;
}
