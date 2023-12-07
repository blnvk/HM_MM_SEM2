#include <iostream>
#include <cmath>

class vector3D {
private:
    int x;
    int y;
    int z;
public:
    vector3D() : x(0), y(0), z(0){ }
    vector3D(int a, int b, int c) : x(a), y(b), z(c){ }
    vector3D operator +(vector3D & other){ //cложение векторов
        vector3D tmp;
        tmp.x = this->x + other.x;
        tmp.y = this->y + other.y;
        tmp.z = this->z + other.z;
    }
    vector3D operator -(vector3D & other){ //вычитание векторов
        vector3D tmp;
        tmp.x = this->x - other.x;
        tmp.y = this->y - other.y;
        tmp.z = this->z - other.z;
    }
    int scal_prod(vector3D a) { //скалярное произведение
        int product;
        product = (x * a.x) + (y * a.y) + (z * a.z);
        return product;
    }

    int scal(int sc) //умножение на скаляр
    {
        vector3D tmp;
        tmp.x = sc * x;
        tmp.y = sc * y;
        tmp.z = sc * z;
    }

    float lenght(){ //длина вектора
    float ll;
    ll = sqrt(x*x + y*y + z*z);
    return ll;
    }
};


int main(){
    vector3D a(1, 5, 7);
    vector3D b(2, 0, 4);
    std::cout << "Length of vector is " << a.lenght() << std::endl;
    std::cout << "Product of vectors a and b is " << a.scal_prod(b) << std::endl;
    return 0;
}