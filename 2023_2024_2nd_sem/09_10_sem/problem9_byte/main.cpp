///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write a program to copy a binary file to another file in reverse byte order.
///////////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <vector>
#include <iostream>

void reverseCopyBinaryFile(const std::string& inputFilePath, const std::string& outputFilePath) {
    std::ifstream inputFile(inputFilePath, std::ios::binary | std::ios::ate);
    if (!inputFile) {
        std::cerr << "Could not open the input file: " << inputFilePath << std::endl;
        return;
    }

    std::streamsize size = inputFile.tellg();
    inputFile.seekg(0, std::ios::beg);

    std::vector<char> buffer(size);
    if (!inputFile.read(buffer.data(), size)) {
        std::cerr << "Error reading from input file." << std::endl;
        return;
    }

    inputFile.close();

    std::ofstream outputFile(outputFilePath, std::ios::binary);
    if (!outputFile) {
        std::cerr << "Could not open the output file: " << outputFilePath << std::endl;
        return;
    }

    for (std::streamsize i = size - 1; i >= 0; --i) {
        outputFile.write(&buffer[i], 1);
    }

    outputFile.close();
}

int main() {
    reverseCopyBinaryFile("input_binary.bin", "output_reversed.bin");
    return 0;
}
