///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write a function to find and replace 
/// all occurrences of a word in a file.
///
///////////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <sstream>
#include <iostream>

void findAndReplaceInFile(const std::string& filePath, const std::string& toFind, const std::string& toReplace) {
    std::ifstream file(filePath);
    if (!file) {
        std::cerr << "Could not open the file - '" << filePath << "'" << std::endl;
        return;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string content = buffer.str();
    file.close();

    size_t pos = content.find(toFind);
    while (pos != std::string::npos) {
        content.replace(pos, toFind.length(), toReplace);
        pos = content.find(toFind, pos + toReplace.length());
    }

    std::ofstream outFile(filePath);
    outFile << content;
    outFile.close();
}

int main() {
    findAndReplaceInFile("file.txt", "oldWord", "newWord");
    return 0;
}
