//  D. Kousuke's Assignment
#include <bits/stdc++.h>

using i64 = long long int;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void nhir() {
    int n;
    std::cin >> n;
    std::vector<i64> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> pre[i];
        pre[i] += pre[i - 1];
    }
    std::set<i64> se;
    int cnt = 0;
    for (auto i: pre) {
        if (se.count(i) == 0) {
            se.insert(i);
        } else {
            se.clear();
            se.insert(i);
            cnt++;
        }
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
