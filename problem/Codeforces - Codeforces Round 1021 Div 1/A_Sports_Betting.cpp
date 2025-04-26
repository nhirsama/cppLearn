//  A. Sports Betting
#include <bits/stdc++.h>

using i64 = long long int;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void nhir() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &i: a) std::cin >> i;
    std::map<int, int> cnt;
    for (int x: a) cnt[x]++;
    for (auto [d, c]: cnt) {
        if (c >= 4) {
            std::cout << "Yes\n";
            return;
        }
    }
    bool flag = false;
    int day = -1;
    for (auto [d,c]: cnt) {
        if (day != d - 1) flag = false, day = d;
        else day++;
        if (flag) {
            if (c >= 2) {
                std::cout << "Yes\n";
                return;
            }
        } else {
            if (c >= 2) flag = true;
        }
    }
    std::cout << "No\n";
}

signed main() {
    IOS;
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
