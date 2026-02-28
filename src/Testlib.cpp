#include <bits/stdc++.h>

int main() {
    long long a = 41000000;
    while (a++) {
        std::mt19937_64 mt(a);
        if ((mt() % 100000000) == 20250601) {
            std::cout << a << std::endl;
            return 0;
        }
    }
    return 0;
}
