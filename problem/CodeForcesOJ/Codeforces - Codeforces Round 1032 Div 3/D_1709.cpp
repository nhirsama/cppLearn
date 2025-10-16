//  D. 1709
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

/*
 *1 2 3 4 5
 *6 7 8 9 10
 *1 3 5 7 9
 *2 4 6 8 10
 */
void nhir() {
    i32 n;
    std::cin >> n;
    std::vector<i32> a(n), b(n);
    for (auto &i: a) std::cin >> i;
    for (auto &i: b) std::cin >> i;
    std::vector<std::array<i32, 2> > op;
    auto swapa = [&](i32 i) {
        std::swap(a[i], a[i + 1]);
        op.push_back({1, i});
    };
    auto swapb = [&](i32 i) {
        std::swap(b[i], b[i + 1]);
        op.push_back({2, i});
    };
    auto swapab = [&](i32 i) {
        std::swap(a[i], b[i]);
        op.push_back({3, i});
    };
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swapa(j);
            }
        }
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (b[j] > b[j + 1]) {
                swapb(j);
            }
        }
    }
    for (i32 i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            swapab(i);
        }
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (b[j] > b[j + 1]) {
                swapb(j);
            }
        }
    }
    std::cout << op.size() << endl;
    for (auto [x, y]: op) {
        std::cout << x << ' ' << y + 1 << endl;
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
