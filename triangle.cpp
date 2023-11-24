#include <iostream>
#include <cmath>

class triangle{ //класс треугольника
public:
    float a; //полями являются стороны
    float b;
    float c;

    triangle(float z){ //конструктор для равностороннего треугольника
        a = z;
        b = z;
        c = z;
    };

    triangle(float x, float y,  float z) { //конструктор для проивзольного треугольника
        a = x;
        b = y;
        c = z;
    };

    float perimetr() { //функция для нахождения периметра
        float P;
        P = a + b + c;
        return P;
    }
    float tangle_alfa(){ //функции для нахождения углов с помощью теоремы косинусов
        float alfa = acos((a*a + c*c - b*b)/(2*a*c));
    }
    float tangle_beta(){
        float beta = acos((a*a + b*b - c*c)/(2*a*b));
    }
    float tangle_gamma(){
        float gamma = acos((b*b + c*c - a*a)/(2*b*c));
    }

};

class equilateral : public triangle{ //дочерний класс -- класс равностороннего треугольника
public:
    equilateral(float z): triangle(z) {};
    float square = square_calc();
    float square_calc(){ //метод вычисления площади через полупериметр
        float p = (3* a)/2;
        float square = sqrt(p*(p - a)*(p - a)*(p - a));
        return square;
    }
    void print()
    {
      std::cout << square << std::endl; //функция вывода
    }
};
int main() {
    equilateral abc(5);
    abc.print();
    return 0;
}

