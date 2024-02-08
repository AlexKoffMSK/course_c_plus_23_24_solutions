///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for a Problem: Pointers - Swap Variables
/// \version    0.1.0
/// \date       22.01.2022
///
/// TASK DESCRIPTION
///
/// Write a program that reads two integers from the standard input and swaps
/// their values using pointers. Print the swapped values.
///
///////////////////////////////////////////////////////////////////////////////
#include <iostream>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a, b;
    std::cout << "Enter two numbers: ";
    std::cin >> a >> b;

    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;

    swap(&a, &b);

    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;

    return 0;
}
