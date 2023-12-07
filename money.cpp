#include <iostream>
#include <cmath>
#include <string>

class BMoney {
private:
    float money = 0;
    float result;
    std::string user_money;
    std::string program_money;
    std::string program_money2;
    std::string showing_money;
public:
    void mstold(){
        std::cout << "Put your money here " << std::endl; //принимает строку в формате "$1,000,000.00"
                                                          // а затем переводит ее в число в формате float
        std::cin >> user_money;
        for (const char c: user_money) {
            if ((c != ',') && (c != '$')) {
                program_money += c;
            }
        }
        money = std::stof(program_money);
        result = money;

    }
    void ldtoms(){  //выводит значение в строковом формате
        program_money2 = std::to_string(money);
        showing_money = '$' + program_money2;
    }

    void print() {
        std::cout << "money: " << showing_money << std::endl; //функция вывода
    }

    float madd(BMoney m1, BMoney m2) { //суммирует значения
        float res = m1.money + m2.money;
        m1.result = res;
        return res;
    }

};
int main() { //программа в которой пользователь вводит несколько строк, затем получает сумма
    BMoney m1;
    BMoney m2;
    BMoney m3;
    m1.mstold();
    m2.mstold();
    m3.mstold();
    float sum = (m1.madd(m1, m2) + m1.madd(m1, m3) + m1.madd(m2, m3))/2;
    std::cout << sum << std::endl;
    return 0;
}