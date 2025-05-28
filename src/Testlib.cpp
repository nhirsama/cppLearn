#include <bits/stdc++.h>
using i128 = __int128;

int main() {
    auto aa = std::chrono::high_resolution_clock::now() - std::chrono::high_resolution_clock::now();
    auto bb = std::chrono::high_resolution_clock::now() - std::chrono::high_resolution_clock::now();
    int t;
    std::cin >> t;

    for (int j = 0; j < t; j++) {
        std::vector<int> a(1000000);
        auto t1 = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 1000000; i++) {
            a[i] = i;
        }
        auto t2 = std::chrono::high_resolution_clock::now();
        std::vector<int> b(1000000);
        auto t3 = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 1000000 - 1; i++) {
            a[i + 1] = a[i] + i;
        }
        auto t4 = std::chrono::high_resolution_clock::now();
        aa += t2 - t1;
        bb += t4 - t3;
        //std::cout << t4 - t3 << ' ' << t2 - t1 << std::endl;
    }
    std::cout << aa / t << ' ' << bb / t;
    return 0;
}
