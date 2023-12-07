#include <iostream>
#include <cmath>
class distance{
private:
    int feet;
    float inches;
public:
    distance() {feet = 0; inches = 0;} //конструктор без аргументов инициализирует нулями
    distance(float fltfeet) { //конструктор переводит float в футы и дюймы
        feet = int(fltfeet);
        inches = 12 *(fltfeet - feet);
    }
    distance(int ft, float inch){ //сразу вводятся футы и дюймы отдельно
        feet = ft; inches = inch;
    }
    void print(){ //функция выводы
        std::cout << "Distance is "<< feet << " feet " << inches << " inches" << std::endl;
    }
    friend distance operator+(distance d1, distance d2); //дружественная функция -- перегрузка +
    friend distance operator*(distance d1, distance d2); //дружественная функция -- перегрузка *
};

    distance operator+(distance d1 ,distance d2){
        int ft = d1.feet + d2.feet;
        float in = d1.inches + d2.inches;
        if (in >= 12) {
            in -= 12;
            ft += 1;
        }
        return distance(ft, in);
    }

    distance operator*(distance d1, distance d2) {
        float dis1 = float(d1.feet) + (d1.inches/12.0);
        float dis2 = float(d2.feet) + (d2.inches/12.0);
        float result = dis1 * dis2;
        int ft = int(result);
        float in = (result - ft)*12;
        return distance(ft, in);
    }

int main(){
        distance d1 (12.5);
        distance d2;
        d2 = d1 * 10.0; //такие дружественные перегруженные операторы
                        // позволяют не только умножать класс на класс,
                        // но и вводить в качестве аргумента число
        d1.print();
        d2.print();
    return 0;
}