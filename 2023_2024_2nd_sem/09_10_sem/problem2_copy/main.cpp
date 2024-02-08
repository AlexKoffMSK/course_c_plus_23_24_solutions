///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Create a function that copies the content of one file to another file.
///
///////////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <iostream>

void copyFile(const std::string& sourceFilePath, const std::string& destinationFilePath) {
    std::ifstream sourceFile(sourceFilePath, std::ios::binary);
    std::ofstream destinationFile(destinationFilePath, std::ios::binary);

    if (!sourceFile) {
        std::cerr << "Error opening source file." << std::endl;
        return;
    }

    if (!destinationFile) {
        std::cerr << "Error opening destination file." << std::endl;
        return;
    }

    destinationFile << sourceFile.rdbuf();

    sourceFile.close();
    destinationFile.close();
}

int main() {
    copyFile("source.txt", "destination.txt");
    return 0;
}
