////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem 4: "Some functions for dealing with strings".
/// \author     Sergey Shershakov
/// \version    0.1.0
/// \date       19.01.2021
///             This code is for educational purposes of the course "Introduction
///             to programming" provided by the Faculty of Computer Science
///             at the Higher School of Economics.
///
/// Try to use functions for dealing with strings:
/// 1) strcmp, strlen for c-strings;
/// 2) string:: size(), length(), operator<, operator+, operator= etc for
///    std::string-s.
///
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include <string>

int main()
{
    const char* str1 = "Hello";
    const char* str2 = "World";
    char combined[20];

    std::cout << "Comparing C-strings: " << std::strcmp(str1, str2) << std::endl;
    std::cout << "Length of first C-string: " << std::strlen(str1) << std::endl;

    std::strcpy(combined, str1);
    std::strcat(combined, " ");
    std::strcat(combined, str2);
    std::cout << "Combined C-string: " << combined << std::endl;

    std::string string1 = "Hello";
    std::string string2 = "World";
    std::string combinedString = string1 + " " + string2;

    std::cout << "Comparing std::strings: " << (string1 < string2) << std::endl;
    std::cout << "Length of first std::string: " << string1.length() << std::endl;
    std::cout << "Combined std::string: " << combinedString << std::endl;

    return 0;
}
