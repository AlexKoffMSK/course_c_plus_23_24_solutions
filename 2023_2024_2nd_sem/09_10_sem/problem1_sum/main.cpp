///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write a function to read a file containing integers 
/// separated by spaces or newlines, sum these integers, and write the result to another file.
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cmath>
#include <stdio.h>
#include <fstream>

int sumIntegersInFile1(const char* inputFilePath, const char* outputFilePath) {
    FILE* inputFile = fopen(inputFilePath, "r");
    if (inputFile == NULL) {
        return -1;
    }
    int sum = 0, temp;
    while (fscanf(inputFile, "%d", &temp) == 1) {
        sum += temp;
    }
    fclose(inputFile);
    FILE* outputFile = fopen(outputFilePath, "w");
    if (outputFile == NULL) {
        return -1;
    }
    fprintf(outputFile, "%d", sum);
    fclose(outputFile);
    return sum;
}
int sumIntegersInFile(const char* inputFilePath, const char* outputFilePath) {
    std::ifstream inputFile(inputFilePath);
    std::ofstream outputFile(outputFilePath);
    int sum = 0, temp;

    while (inputFile >> temp) {
        sum += temp;
    }
    outputFile << sum;
    inputFile.close();
    outputFile.close();
    return sum;
}
int main() {
    sumIntegersInFile("input.txt", "output.txt");
    return 0;
}
