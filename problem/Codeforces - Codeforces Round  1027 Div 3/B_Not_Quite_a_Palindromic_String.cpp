//  B. Not Quite a Palindromic String
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
#define endl '\n'


void nhir() {
    i32 n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;
    i32 cnt0 = 0, cnt1 = 0;
    for (auto i: s) {
        if (i == '0') cnt0++;
        else cnt1++;
    }
    if (n / 2 - k < 0) {
        std::cout << "NO\n";
        return;
    }
    if (cnt0 < n / 2 - k || cnt1 < n / 2 - k) {
        std::cout << "NO\n";
    } else {
        if ((((cnt0 - (n / 2 - k)) & 1) == 0)) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
