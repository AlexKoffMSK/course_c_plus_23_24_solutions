///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for a Problem: Pointers - Find Maximum Element
/// \version    0.1.0
/// \date       22.01.2022
///
/// TASK DESCRIPTION
///
/// Write a program that reads an array of integers from the standard input and
/// finds the maximum element using pointers. Print the maximum element.
///
///////////////////////////////////////////////////////////////////////////////
#include <iostream>

int findMaximum(int* arr, int size) {
    int max = *arr; 
    for (int i = 1; i < size; ++i) {
        if (*(arr + i) > max) {
            max = *(arr + i);
        }
    }
    return max;
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

    int max = findMaximum(arr, n);
    std::cout << "Maximum element is: " << max << std::endl;

    delete[] arr;
    return 0;
}
