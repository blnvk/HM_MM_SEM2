#include <iostream>
#include <cmath>
 class array {
public:
    char *arr;
    int N;
    array(){
        N = 1;
        arr = new char[N];
        for (int i = 0; i < N; ++i) {
            arr[i]= 0;
        }
    }
    array(int n) {
        N = n;
        arr = new char[N];
        for (int i = 0; i < N; ++i) {
            arr[i] = 0;
        }
    }
    virtual array operator +(const array & other) {
        for (int i = 0; i < N; i++) {
            this->arr[i] += other.arr[i];
        }
    }
};

class money: public array {
private:
public:
    money(int N): array(N) {};
    void input(){
        std::cout << "Put your moneyyyy" << std::endl;
        for (int i = 0; i < N; ++i) {
            std::cin >> arr[i];
        }
    }
    void output(){
        for (int i = 0; i < N; ++i) {
            std::cout << int(arr[i]) - 96;
        }
    }
};
int main(){
    money a(2);
    money b(2);

    a.input();
    b.input();


    a + b;
    a.output();

    return 0;
}

