////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem 3: "Reading text strings using getline".
/// \author     Sergey Shershakov
/// \version    0.1.0
/// \date       19.01.2021
///             This code is for educational purposes of the course "Introduction
///             to programming" provided by the Faculty of Computer Science
///             at the Higher School of Economics.
///
/// Train reading text string with spaces and other special symbol using
/// cin.getline() for c-strings and std::getline() for std::string-s.
/// Then, consider the “read lines until first empty line” idiom.
///
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>

int main()
{
    const int SIZE = 256;
    char cstr[SIZE];
    std::string str;

    std::cout << "Enter a C-string: ";
    std::cin.getline(cstr, SIZE);
    std::cout << "You entered: " << cstr << std::endl;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer

    std::cout << "Enter a std::string (with spaces): ";
    std::getline(std::cin, str);
    std::cout << "You entered: " << str << std::endl;

    std::cout << "Enter multiple lines (an empty line to stop):\n";
    while (true)
    {
        std::getline(std::cin, str);
        if (str.empty())
            break;
        std::cout << "You entered: " << str << std::endl;
    }

    return 0;
}
