/*******************************************************************************
 * Workshop 2/Task 1
 * Studying properties of some basic datatypes.
 *
 * Use operator sizeof to explore size of all important basic datatypes:
 *  char, short, int, long, long long, double, bool
 *
 * For storing results use named variables of size_t for some types from the
 * list above.
 * Also, try to create complex expressions for output formatted results to
 * std::cout.
 *
 ******************************************************************************/
#include <iostream>

int main()
{
    std::cout << "Exploring sizes of basic datatypes:\n";

    size_t sizeOfChar = sizeof(char);
    size_t sizeOfShort = sizeof(short);
    size_t sizeOfInt = sizeof(int);
    size_t sizeOfLong = sizeof(long);
    size_t sizeOfLongLong = sizeof(long long);
    size_t sizeOfDouble = sizeof(double);
    size_t sizeOfBool = sizeof(bool);

    std::cout << "Size of char: " << sizeOfChar << " byte(s)\n";
    std::cout << "Size of short: " << sizeOfShort << " byte(s)\n";
    std::cout << "Size of int: " << sizeOfInt << " byte(s)\n";
    std::cout << "Size of long: " << sizeOfLong << " byte(s)\n";
    std::cout << "Size of long long: " << sizeOfLongLong << " byte(s)\n";
    std::cout << "Size of double: " << sizeOfDouble << " byte(s)\n";
    std::cout << "Size of bool: " << sizeOfBool << " byte(s)\n";

    return 0;
}
