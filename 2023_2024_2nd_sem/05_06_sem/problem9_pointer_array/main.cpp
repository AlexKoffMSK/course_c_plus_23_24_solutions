///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for a Problem: Pointers - Count Elements
/// \version    0.1.0
/// \date       22.01.2022
///
/// TASK DESCRIPTION
///
/// Write a program that reads an array of integers from the standard input and
/// counts the number of elements in the array using pointers. Print the count.
///
///////////////////////////////////////////////////////////////////////////////
#include <iostream>

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    int* arr = new int[n];
    std::cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    std::cout << "Number of elements in the array: " << n << std::endl;

    delete[] arr;
    return 0;
}
