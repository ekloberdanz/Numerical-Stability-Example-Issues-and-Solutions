#include <iostream>
#include <math.h> 


float squared_division_stable(float gradient, float a, float b) {
    float result = -gradient * (a / b) / b;
    return result;
}

float squared_division_unstable(float gradient, float a, float b) {
    float result = -gradient * a / (b * b);
    return result;
}

int main() {
    // float gradient = 0.07;
    // float a = 0.05;

    float gradient = 0.00005;
    float a = 0.00007;
    float b_small = 0.0000000000000000009;
    float b_large = 99999999999999999.0;

    std::cout << "Stable division result: " << squared_division_stable(gradient, a, b_small) << std::endl;
    std::cout << "Untable division result: " << squared_division_unstable(gradient, a, b_small) << std::endl;

    std::cout << "Stable division result: " << squared_division_stable(gradient, a, b_large) << std::endl;
    std::cout << "Untable division result: " << squared_division_unstable(gradient, a, b_large) << std::endl;
}
