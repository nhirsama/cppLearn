//
// Created by ling on 25-6-6.
//
#include <bits/stdc++.h>

int main() {
    std::random_device rd;
    std::mt19937 mt(rd());
    int cnta = 0, cntb = 0;
    while (std::abs(cnta - cntb) <= 5) {
        auto ran = mt();
        if (ran & 1) cnta++;
        else cntb++;
    }
    std::cout << std::format("{}", (cntb > cnta ? "去二餐" : "去南门")) << '\n';
    return 0;
}
