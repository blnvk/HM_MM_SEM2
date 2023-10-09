#include <iostream>
#include <cmath>


class complex_numbers { //класс комплексных чисел
private:
    float re;
    float im;
public:

    complex_numbers(float value_re, float value_im) { //конструктор класса
        re = value_re; //вещественная часть числа
        im = value_im; //мнимая часть числа
    }
    float get_value_im() { //геттер для мнимой части
        return im;
    }

    float get_value_re(){ //геттер для вещественной части
        return re;
    }
    float absolute() { //функция для подсчета модуля вещественного числа
        float abs = sqrt((re*re + im*im));
        return abs;
    }

    void print() { // вывод числа в алгебраической форме
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
};

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
