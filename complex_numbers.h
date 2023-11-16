class complex_numbers { //класс комплексных чисел
private:
    float re;
    float im;
public:
    complex_numbers(float value_re, float value_im) ; //конструктор класса

    float get_value_im(); //геттер для мнимой части

    float get_value_re() ;//геттер для вещественной части

    float absolute(); //функция для подсчета модуля вещественного числа

    void print() ; // вывод числа в алгебраической форме
};