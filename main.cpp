#include <iostream>

class point{
public:
    float x;
    float y;

    void print() {
        std::cout << "x " << x << "\ty " << y << std::endl;
    }
};

int main() {
    point a;
    a.x = 1;
    a.y = 0.5;

    a.print();

    return 0;
}