#include <iostream>
#include <cmath>

class figure { //родительский класс (абстрактный)
public:
    virtual float square()= 0; //чистая виртуальная функция
    virtual float perimetr() = 0; //чистая виртуальная функция
};

class circle: public figure { //производный класс
private:
    float pi = M_PI;
    float rad;
public:
    circle(float r) : rad(r) { }
    float square() override { //переопределение функции
        return pi*rad*rad;
    }
    float perimetr() override { //переопределение функции
        return 2*pi*rad;
    }
};

class rectangle: public figure {
private:
    float width;
    float height;

public:
    rectangle(float w, float h) : width(w), height(h){ }
    float square() override { //переопределение функции
        return width*height;
    }
    float perimetr() override { //переопределение функции
        return 2*width + 2*height;
    }
};

class trapezium: public figure {
private:
  float height;
  float up;
  float down;
  float left;
  float  right;

public:
    trapezium(float h, float u, float d, float l, float r) : height(h), up(u), down(d), left(l), right(r) { }
    float perimetr() override{ //переопределение функции
        return up+left+down+right;
    }
    float square() override { //переопределение функции
        return (up + down) * height / 2;
    }
};


int main(){
    trapezium a(4, 4, 10, 5, 5);
    circle b(5);
    rectangle c(3, 4);

    std::cout << "Square is: "<< a.square() << std::endl;
    std::cout << "Perimetr is " << b.perimetr() << std::endl;
    std::cout << "Square is " << c.square() << std::endl;

    return 0;
}