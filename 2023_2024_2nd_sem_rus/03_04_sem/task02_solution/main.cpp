/*
Написать функцию, которая подсчитывает количество символов в строке с помощью указателей.

Входные данные: Строка (например, "Hello World").
Количество символов: 11
*/

#include <iostream>

int count_letters(char* s) {
    int count = 0;
    while (*s != '\0') {
        count += 1;
        s++;
    }
    return count;
}

int main() {
    char str[] = "Hello World!";
    // char* str = "Hello World!";
    std::cout << count_letters(str);
    delete[] str;
}