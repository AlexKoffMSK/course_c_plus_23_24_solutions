///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Create a program to extract a specific line number from a text file and write it to another file.
///////////////////////////////////////////////////////////////////////////////

#include <fstream>
#include <iostream>
#include <string>

void extractLineToFile(const std::string& inputFilePath, const std::string& outputFilePath, int lineNum) {
    std::ifstream inputFile(inputFilePath);
    std::ofstream outputFile(outputFilePath);
    std::string line;
    int currentLine = 0;

    if (!inputFile) {
        std::cerr << "Could not open input file: " << inputFilePath << std::endl;
        return;
    }
    
    if (!outputFile) {
        std::cerr << "Could not open output file: " << outputFilePath << std::endl;
        return;
    }

    while (getline(inputFile, line)) {
        ++currentLine;
        if (currentLine == lineNum) {
            outputFile << line;
            break; 
        }
    }

    if (currentLine < lineNum) {
        std::cerr << "The file does not contain line number " << lineNum << std::endl;
    }

    inputFile.close();
    outputFile.close();
}

int main() {
    extractLineToFile("input.txt", "specific_line.txt", 3);
    return 0;
}


