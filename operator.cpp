#include <iostream>
#include <cmath>

class rational {
private:
     int  chisl; //числитель
     int znam; //знаменатель
     int max(int x, int y) { //функция максимума
         if (x >= y) {
             return x;
         }
         else {
             return y;
         }
     }
     int frac_nod(int a, int b){ //функция нахождения наибольшего общего делителя
         if (b == 0) return a;
         return frac_nod(b, a % b);
     };
     rational reduce() { //функция сокращения дроби
         int a = max(abs(chisl), abs(znam));
         int sgn;
         if (chisl * znam >= 0) {
             sgn = 1;
         }
         else {
             sgn = -1;
         }
         int nod = frac_nod(chisl, znam);
         return rational(sgn * (abs(chisl)/nod), abs(znam)/ nod);
     }
public:
    rational() { //конструктор по умолчанию
        chisl = 1;
        znam = 1;
    };
    rational(int z) { //конструктор для ввода целого числа и представления его в виде дроби
        chisl = z;
        znam = 1;
    };
    rational(int z1, int z2) { //конструктор для ввода дроби
        chisl = z1;
        znam = z2;
    };

    void print() { //функция для вывода дроби
        if (znam == 1) {
            std::cout << "Integer number " << chisl << std::endl;
        }
        else {std::cout << "Rational number: " << chisl << "/" << znam << std::endl;
        }
    };

    rational operator +(const rational & other){ //перегрузка оператора +
        rational temp;
        temp.chisl = this->chisl * other.znam + this->znam * other.chisl;
        temp.znam = this->znam * other.znam;
        return temp.reduce();
    };

    rational operator *(const rational & other){ //перегрузка оператора *
        rational temp;
        temp.chisl = this->chisl * other.chisl;
        temp.znam = this->znam * other.znam;
        return temp.reduce();
    };

    rational operator -(const rational & other){ //перегрузка оператора -
        rational temp;
        temp.chisl = this->chisl * other.znam - this->znam * other.chisl;
        temp.znam = this->znam * other.znam;
        return temp.reduce();
    };

    rational operator /(const rational & other){ //перегрузка оператора /
        rational temp;
        temp.chisl = this->chisl * other.znam;
        temp.znam = this->znam * other.chisl;
        return temp.reduce();
    };

};

int main(){
    rational a(3, 2);
    rational b(1, 2);

    rational c = a / b;

    b.print();
    a.print();
    c.print();
    return 0;
}




