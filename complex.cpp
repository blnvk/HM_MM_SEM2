#include <iostream>
#include <cmath>
#include "complex_numbers.h"

complex_numbers::complex_numbers(float value_re, float value_im) { //конструктор класса
    re = value_re; //вещественная часть числа
    im = value_im; //мнимая часть числа
}
float complex_numbers::get_value_im() { //геттер для мнимой части
    return im;
}
float complex_numbers::get_value_re(){ //геттер для вещественной части
    return re;
}
float complex_numbers::absolute() { //функция для подсчета модуля вещественного числа
    float abs = sqrt((re*re + im*im));
    return abs;
}

void complex_numbers::print() { // вывод числа в алгебраической форме
    if (im == 0)  {
        std::cout << re << std::endl;
    }
    else if(re == 0) {
        std::cout << im << "i" << std::endl;
    }
    else {
        std::cout << re << " + " << im << "i" << std::endl;
    }
}

