///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem: Execute Callback
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write a function `void executeCallback(void (*callback)())` that takes a 
/// function pointer and executes the callback function.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

void executeCallback(void (*callback)()) {
    callback();
}
void func1() {
    std::cout << "func1" << '\n';
}
void func2() {
    std::cout << "func2" << '\n';
}
int main()
{
    void (*link)() = func1;
    executeCallback(link);
    executeCallback(func2);
    return 0;
}
