//  C. Sakurako's Field Trip
#include <bits/stdc++.h>

using i64 = long long int;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void nhir() {
    int n;
    std::cin >> n;
    std::vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) std::cin >> v[i];
    for (int it = n / 2 - 1; it; it--) {
        if (v[it] == v[it + 1] || v[n - it + 1] == v[n - it]) {
            std::swap(v[it], v[n - it + 1]);
        }
    }
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        if (v[i] == v[i + 1]) cnt++;
    }
    std::cout << cnt << endl;
}

signed main() {
    IOS;
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
