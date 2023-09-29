#include <iostream>

class point {

private:
    float x;
    float y;
public:
    void print() {
        std::cout << "x " << x << "\ty " << y << std::endl;
    }

    float Get_x_data () {
        return x;
    }

    void Set_x_value (float value_x) {
        x = value_x;
    }
};

int main() {
    
    return 0;
}