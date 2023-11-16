#include <iostream>
#include <cmath>
#include "complex.cpp"

int main() {
    complex_numbers a(3, 4);
    complex_numbers b(4, 7);
    a.print();
    b.print();
    float lenght = a.absolute();
    float lenght1 = b.absolute();
    std::cout << "abs of a "<< lenght << "\t";
    std::cout << "abs of b " << lenght1 << std::endl;

    return 0;
}