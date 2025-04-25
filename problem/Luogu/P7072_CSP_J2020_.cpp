//  P7072 [CSP-J2020] 直播获奖
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = int;
using pii = std::pair<i32, i32>;
constexpr int N = 1e5 + 10;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void nhir() {
    int n, w;
    std::cin >> n >> w;
    std::vector<int> s(601);
    for (int i = 1; i <= n; i++) {
        int v;
        std::cin >> v;
        s[v]++;
        int t = std::max(1, i * w / 100), sum = 0;
        for (int j = 600; ~j; j--) {
            sum += s[j];
            if (sum >= t) {
                std::cout << j << ' ';
                break;
            }
        }
    }
}

signed main() {
    IOS;
    i32 T = 1;
    while (T--) nhir();
    return 0;
}
