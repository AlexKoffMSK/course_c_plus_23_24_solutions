///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write a program that removes all blank 
/// lines from a text file and writes the result 
/// to a new file.
///
///////////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <iostream>
#include <string>

void removeBlankLines(const std::string& inputFilePath, const std::string& outputFilePath) {
    std::ifstream inputFile(inputFilePath);
    std::ofstream outputFile(outputFilePath);
    std::string line;

    if (!inputFile) {
        std::cerr << "Could not open input file: " << inputFilePath << std::endl;
        return;
    }
    
    if (!outputFile) {
        std::cerr << "Could not open output file: " << outputFilePath << std::endl;
        return;
    }

    while (getline(inputFile, line)) {
        if (!line.empty() && line.find_first_not_of(" \t") != std::string::npos) {
            outputFile << line << std::endl;
        }
    }

    inputFile.close();
    outputFile.close();
}

int main() {
    std::string inputFilePath = "input.txt";
    std::string outputFilePath = "output_no_blanks.txt";
    removeBlankLines(inputFilePath, outputFilePath);
    return 0;
}
