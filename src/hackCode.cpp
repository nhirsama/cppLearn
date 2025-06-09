#include <bits/stdc++.h>

signed main() {
    std::cout << 10000 << std::endl;
    for (int i = 0; i < 1e4; i++) {
        std::cout << 20 << std::endl;
        for (int j = 0; j < 20; j++) {
            std::cout << 20 << " \n"[j == 19];
        }
        for (int j = 0; j < 20; j++) {
            std::cout << 19 << " \n"[j == 19];
        }
    }
    return 0;
}
