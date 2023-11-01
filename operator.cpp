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

    bool operator == (const rational & other){
        rational tmp = *this;
        rational tmp0 = other;
        rational tmp1 = tmp.reduce();
        rational tmp2 = tmp0.reduce();
        if (tmp1.znam == tmp2.znam && tmp1.chisl == tmp2.chisl) {
            return true;
        }
        else {
            return false;
        }
    }

    bool operator != (const rational & other) {
        rational tmp = *this;
        rational tmp0 = other;
        rational tmp1 = tmp.reduce();
        rational tmp2 = tmp0.reduce();
        if (tmp1.znam == tmp2.znam && tmp1.chisl == tmp2.chisl) {
            return false;
        } else {
            return true;
        }
    }

    bool operator >(const rational & other){
        rational tmp = *this;
        rational tmp0 = other;
        tmp.chisl *= tmp0.znam;
        tmp0.chisl *= tmp.znam;
        return (tmp.chisl > tmp0.chisl);
    }
    bool operator <(const rational & other){
        rational tmp = *this;
        rational tmp0 = other;
        tmp.chisl *= tmp0.znam;
        tmp0.chisl *= tmp.znam;
        return (tmp.chisl < tmp0.chisl);
    }
    bool operator <=(const rational & other){
        rational tmp = *this;
        rational tmp0 = other;
        tmp.chisl *= tmp0.znam;
        tmp0.chisl *= tmp.znam;
        return (tmp.chisl <= tmp0.chisl);
    }
    bool operator >=(const rational & other){
        rational tmp = *this;
        rational tmp0 = other;
        tmp.chisl *= tmp0.znam;
        tmp0.chisl *= tmp.znam;
        return (tmp.chisl >= tmp0.chisl);
    }

};

int main(){
    rational a(1, 2);
    rational b(2, 4);

    rational c = a + b;
    bool result = a >= b;
    std::cout << result << std::endl;
    b.print();
    a.print();
    c.print();


    return 0;
}

