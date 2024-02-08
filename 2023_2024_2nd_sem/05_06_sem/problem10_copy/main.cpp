///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for a Problem: Pointers - Copy Array
/// \version    0.1.0
/// \date       22.01.2022
///
/// TASK DESCRIPTION
///
/// Write a program that reads an array of integers from the standard input,
/// creates a new array, copies the elements from the original array to the new
/// array using pointers, and then prints the new array.
///
///////////////////////////////////////////////////////////////////////////////
#include <iostream>

void copyArray(int* source, int* dest, int size) {
    for (int i = 0; i < size; ++i) {
        *(dest + i) = *(source + i);
    }
}

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    int* arr = new int[n];
    std::cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int* newArr = new int[n];
    copyArray(arr, newArr, n);

    std::cout << "Copied array: ";
    for (int i = 0; i < n; ++i) {
        std::cout << newArr[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr;
    delete[] newArr;
    return 0;
}
