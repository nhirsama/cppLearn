//
// Created by ling on 25-5-11.
//
//
// Created by ling on 25-5-11.
//
#include <bits/stdc++.h>
using namespace std;
using i32 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i32 n;
    std::cin >> n;
    if (n == 2 || n == 4) {
        std::cout << -1 << endl;
        return 0;
    }
    if ((n & 1) == 0) {
        std::cout << n / 2 << endl;
        std::cout << "1 ";
        for (i32 i = 3; i <= n / 2 + 1; i++) {
            std::cout << i << ' ';
        }
        std::cout << endl;
    } else {
        std::cout << (n + 1) / 2 << endl;
        for (i32 i = 1; i <= (n + 1) / 2; i++) {
            std::cout << i << ' ';
        }
        std::cout << endl;
    }
    //std::cout<<ans<<endl;
}
