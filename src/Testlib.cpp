#include <iostream>
#include <cmath>

int main() {
    double x = 233, y = 666;
    double r = std::sqrt(x*x + y*y);
    double theta = std::acos(x / r);
    double distance = r * (1 + theta);
    std::cout << static_cast<int>(std::round(distance)) << std::endl;
    return 0;
}