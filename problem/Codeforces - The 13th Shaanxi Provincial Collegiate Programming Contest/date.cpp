//
// Created by ling on 25-5-13.
//
#include <bits/stdc++.h>

int main() {
    int cnt = 0;
    for (int i = 0; i <= 20; i++) {
        for (int j = 0; j <= 20; j++) {
            for (int k = 0; k <= 20; k++) {
                for (int m = 0; m <= 20; m++) {
                    std::cout << i << ' ' << j << ' ' << k << ' ' << m << '\n';
                    cnt++;
                }
            }
        }
    }
    std::cout << cnt << std::endl;
}
