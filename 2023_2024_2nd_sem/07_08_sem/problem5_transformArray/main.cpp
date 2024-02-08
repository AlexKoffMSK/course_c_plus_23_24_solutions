///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem: Array Transformation
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write a function `void transformArray(int* arr, int size, int (*transform)(int))`
/// that applies a transformation function to each element of an array.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << ' ';
    std::cout << '\n';
}
void transformArray(int* arr, int size, int (*change)(int)) {
    for (int i = 0; i < size; i++)
        arr[i] = change(arr[i]);
}
int multiply5(int a) {
    return a * 5;
}
int plus100(int a) {
    return a + 100;
}
int main()
{
    int n = 5;
    int* a = new int[n];
    for (int i = 0; i < n; i++)
        a[i] = i + 1;
    printArray(a, n);
    transformArray(a, n, multiply5);
    printArray(a, n);
    transformArray(a, n, plus100);
    printArray(a, n);
    return 0;
}
