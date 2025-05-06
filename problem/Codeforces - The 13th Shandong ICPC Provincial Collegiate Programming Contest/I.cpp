#include <bits/stdc++.h>

int main() {
    int a, b;
    std::cin >> a >> b;
    if (a > 12 || b > 18) {
        std::cout << "No\n";
    } else {
        if (a == 1 || a == 4) {
            if (4 <= b && b <= 12) {
                std::cout << "Yes\n";
            } else {
                std::cout << "No\n";
            }
        } else if (a == 2 || a == 5 || a == 8) {
            if (2 <= b && b <= 6 && b != 4) {
                std::cout << "Yes\n";
            } else {
                std::cout << "No\n";
            }
        } else if (a == 0) {
            if (6 <= b && b <= 18) {
                std::cout << "Yes\n";
            } else {
                std::cout << "No\n";
            }
        } else if (a == 3 || a == 6 || a == 9 || a == 12) {
            if (b == 0) {
                std::cout << "Yes\n";
            } else {
                std::cout << "No\n";
            }
        } else std::cout << "No\n";
    }
}
