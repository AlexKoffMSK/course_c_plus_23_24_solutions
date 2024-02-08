///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
///Write a program that reads a text file, 
// converts all lowercase letters to uppercase, 
// and writes the result to a new file.
///////////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <iostream>
#include <cctype>

void convertToUppercase(const std::string& inputFilePath, const std::string& outputFilePath) {
    std::ifstream inputFile(inputFilePath); 
    std::ofstream outputFile(outputFilePath); 

    if (!inputFile) {
        std::cerr << "Could not open the input file: " << inputFilePath << std::endl;
        return;
    }
    if (!outputFile) {
        std::cerr << "Could not open the output file: " << outputFilePath << std::endl;
        return;
    }

    char c;
    while (inputFile.get(c)) { 
        if (std::islower(c)) { 
            c = std::toupper(c); 
        }
        outputFile.put(c);
    }

    inputFile.close();
    outputFile.close();
}

int main() {
    convertToUppercase("input.txt", "output_uppercase.txt");
    return 0;
}
