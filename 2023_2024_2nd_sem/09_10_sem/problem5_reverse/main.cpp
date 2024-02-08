///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write a program to read the content of a text file 
/// and write its content in reverse order to another file.
///////////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <iostream>
#include <string>

void reverseFileContent(const std::string& inputFilePath, const std::string& outputFilePath) {
    std::ifstream inputFile(inputFilePath, std::ios::ate);
    std::ofstream outputFile(outputFilePath);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Could not open file(s).\n";
        return;
    }

    int fileSize = inputFile.tellg();
    std::string content;

    for (long i = fileSize - 1; i >= 0; --i) {
        inputFile.seekg(i);
        char ch;
        inputFile.get(ch);
        outputFile << ch;
    }
}

int main() {
    reverseFileContent("file.txt", "output_reversed.txt");
    return 0;
}


// #include <fstream>
// #include <iostream>

// void reverseFileContent(const std::string& filePath) {
//     std::fstream file(filePath, std::ios::in | std::ios::out | std::ios::binary);
//     if (!file.is_open()) {
//         std::cerr << "Failed to open the file." << std::endl;
//         return;
//     }
//     char ch1, ch2;
//     long long start = 0;
//     file.seekg(0, std::ios::end);
//     long long end = (int)file.tellg() - 1;
//     while (start < end) {
//         file.seekg(start, std::ios::beg);
//         file.read(&ch1, 1);
//         file.seekg(end, std::ios::beg);
//         file.read(&ch2, 1);

//         file.seekp(start, std::ios::beg);
//         file.write(&ch2, 1);
//         file.seekp(end, std::ios::beg);
//         file.write(&ch1, 1);
//         start++;
//         end--;
//     }
//     file.close();
// }

// int main() {
//     const std::string filePath = "file.txt"; 
//     reverseFileContent(filePath);
//     return 0;
// }