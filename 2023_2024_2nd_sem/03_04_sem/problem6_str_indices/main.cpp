////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem 6: "String indices".
/// \author     Sergey Shershakov
/// \version    0.1.0
/// \date       19.01.2021
///             This code is for educational purposes of the course "Introduction
///             to programming" provided by the Faculty of Computer Science
///             at the Higher School of Economics.
///
/// Work with operator[], and length() property. Consider valid indices of an
/// std::string object.
///
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

int main()
{
    std::string text = "Hello, World!";
    
    std::cout << "The string is: " << text << "\n";
    std::cout << "Length of the string: " << text.length() << "\n";

    for (size_t i = 0; i < text.length(); ++i) {
        std::cout << "Character at index " << i << ": " << text[i] << "\n";
    }

    size_t outOfRangeIndex = text.length(); 
    try {
        std::cout << "Attempting to access index " << outOfRangeIndex << "\n";
        std::cout << "Character at out of range index: " << text.at(outOfRangeIndex) << "\n";
    } catch (const std::out_of_range& e) {
        std::cout << "Error: " << e.what() << "\n";
    }

    return 0;
}
