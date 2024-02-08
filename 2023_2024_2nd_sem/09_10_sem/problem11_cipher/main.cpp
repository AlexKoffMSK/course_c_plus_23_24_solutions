///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
///Develop a program to encrypt the content of 
///a text file
/// using the Caesar cipher and write the
/// encrypted content to another
/// file. For simplicity, shift each letter 
/// by 3 positions in the alphabet.
///////////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <iostream>
#include <cctype> // For isalpha() and tolower()

char caesarCipher(char ch, int shift) {
    if (std::isalpha(ch)) {
        char base = std::islower(ch) ? 'a' : 'A';
        return (26 + ch - base + shift) % 26 + base;
    }
    return ch;
}

void encryptFileContent(const std::string& inputFilePath, const std::string& outputFilePath, int shift = 3) {
    std::ifstream inputFile(inputFilePath);
    std::ofstream outputFile(outputFilePath);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Could not open file(s).\n";
        return;
    }

    char ch;
    while (inputFile.get(ch)) {
        outputFile.put(caesarCipher(ch, shift));
    }
}

int main() {
    encryptFileContent("encrypted.txt", "decripted.txt", -3);
    return 0;
}