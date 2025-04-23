#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    if (n <= 3 || m <= 3) {
        std::cout << "NO\n";
        return;
    }
    if (n % 4 == 0 || m % 4 == 0) {
        std::cout << "YES\n";
        if (n % 4 == 0) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    std::cout << (i / 4) * m + 1 + j << ' ';
                }
                std::cout << '\n';
            }
        } else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    std::cout << j / 4 + 1 + i * (m / 4) << ' ';
                }
                std::cout << '\n';
            }
        }
    } else if (n % 2 == 0 && m % 2 == 0) {

    } else {
        std::cout << "NO\n";
    }
}

int main() {
    int T;
    std::cin >> T;
    while (T--) solve();
}
