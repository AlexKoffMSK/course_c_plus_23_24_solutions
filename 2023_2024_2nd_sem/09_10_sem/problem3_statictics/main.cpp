///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       22.01.2022
///
/// TASK DESCRIPTION
///
/// Write a program to count the number of lines, 
/// words, and characters in a text file.
///
///////////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <iostream>

void countFileStatistics(const std::string& filePath);

int main() {
    countFileStatistics("file.txt");
    return 0;
}

void countFileStatistics(const std::string& filePath) {
    std::ifstream file(filePath);
    std::string line;
    int lines = 0, words = 0, characters = 0;

    while (getline(file, line)) {
        ++lines;
        characters += line.length();
        bool inWord = false;
        for (char c : line) {
            if (isspace(c)) { // c == ' '
                if (inWord) {
                    ++words;
                    inWord = false;
                }
            } else {
                inWord = true;
            }
        }
        if (inWord) { 
            ++words;
        }
    }

    std::cout << "Lines: " << lines << "\nWords: " << words << "\nCharacters: " << characters << std::endl;
}