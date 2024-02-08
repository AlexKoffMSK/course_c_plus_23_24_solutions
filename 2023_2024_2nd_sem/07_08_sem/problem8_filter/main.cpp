///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem: Filter Array
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write a function `int* filter(int* arr, int size, int& newSize, bool (*filterFunc)(int))`
/// that filters an array based on a predicate function and returns a new array.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << ' ';
    std::cout << '\n';
}

// %2 == 0
int* filter(int* arr, int size, int& newSize, bool (*filterFunc)(int)) {
    newSize = 0;
    for (int i = 0; i < size; i++) {
        if (filterFunc(arr[i])) {
            newSize++;
        }
    }
    int* newArr = new int[newSize];
    int j = 0;
    for (int i = 0; i < size; i++) {
         if (filterFunc(arr[i])) {
            newArr[j] = arr[i];
            j += 1;
        }
    }
    return newArr;
}
bool less10(int a) {
    return a < 10;
}
bool even(int a) {
    return a % 2 == 0;
}
int main()
{
    int arr[] = { 10, 3, 4, 19, 20};
    int size = 0;
    int* newArr = filter(arr, 5, size, less10);
    printArray(newArr, size);
    newArr = filter(arr, 5, size, even);
    printArray(newArr, size);
    return 0;
}
