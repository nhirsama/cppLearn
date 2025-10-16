#include <bits/stdc++.h>

void solve() {
    int a, b;
    std::cin >> a >> b;
    std::cout << b * 2 - a << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
}
