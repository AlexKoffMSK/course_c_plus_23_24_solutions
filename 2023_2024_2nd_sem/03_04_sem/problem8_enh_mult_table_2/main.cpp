////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem 8: "Enhanced Multiplication Table".
/// \author     Sergey Shershakov
/// \version    0.1.0
/// \date       19.01.2021
///             This code is for educational purposes of the course "Introduction
///             to programming" provided by the Faculty of Computer Science
///             at the Higher School of Economics.
///
/// Modification of the Problem 7 (Multiplication Table), where a user can
/// repeat a solution multiple times (with using the “do..while” loop).
///
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip> 

int main()
{
    int m, n;
    char choice;

    do {
        std::cout << "Enter two numbers between 1 and 8: ";
        std::cin >> m >> n;

        if (m < 1 || m > 8 || n < 1 || n > 8) {
            std::cout << "Numbers must be between 1 and 8." << std::endl;
        } else {
            for (int i = 1; i <= m; ++i) {
                for (int j = 1; j <= n; ++j) {
                    std::cout << std::setw(4) << i * j;
                }
                std::cout << std::endl;
            }
        }

        std::cout << "Do you want to print another table? (y/n): ";
        std::cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
