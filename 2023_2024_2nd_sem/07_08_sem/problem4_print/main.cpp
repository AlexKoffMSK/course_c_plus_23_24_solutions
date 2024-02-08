///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem: Print Data
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write overloaded functions `void print(int)` and `void print(double)` that
/// print an integer and a double, respectively.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

void print(int a) {
    std::cout << "int " << a << '\n';
}
void print(int a, int b) {
    std::cout << "2 int " << a << '\n';
}
void print(double a) {
    std::cout << "double " << a << '\n';
}
int main()
{
    short a = 10;
    print(1);
    print(a);
    print(a, a);
    print(1.0);
    return 0;
}
