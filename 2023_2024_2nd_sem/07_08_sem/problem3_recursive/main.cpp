///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for a Problem: Sum digits
/// \version    0.1.0
/// \date       22.01.2022
///
/// TASK DESCRIPTION
///
/// Write a program that takes a number and
/// find sum of digits recursively.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

int sum_digits(int n) {
    if (n < 10)
        return n;
    return n % 10 + sum_digits(n / 10);
}

// array (n), calculate sum recursively
int sum_array(int* arr, int n) {
    if (n == 0)
        return 0;
    return *(arr + n - 1) + sum_array(arr, n - 1);
}
int main()
{
    std::cout << sum_digits(12345) << '\n';
    int* arr = new int[5];
    for (int i = 0; i < 5; i++) 
        arr[i] = i + 1;
    std::cout << sum_array(arr, 5);
    return 0;
}
