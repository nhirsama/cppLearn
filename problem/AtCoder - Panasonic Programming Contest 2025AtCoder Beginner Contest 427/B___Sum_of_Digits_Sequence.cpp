//  B - Sum of Digits Sequence
//  21:34
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"AtCoder"};

void nhir() {
    std::map<int, int> m;
    int n;
    std::cin >> n;
    auto f = [&](int i) {
        if (m.find(i) != m.end()) {
            return m[i];
        } else {
            int ans = 0;
            int t = i;
            while (t) {
                ans += t % 10;
                t /= 10;
            }
            return m[i] = ans;
        }
    };
    std::map<int, int> a;
    a[0] = 1;
    auto aa = [&](auto &&self, int b)-> int {
        int ans = 0;
        for (int i = 0; i < b; i++) {
            if (a.find(i) != a.end()) {
                ans += f(a[i]);
            } else {
                ans += f(a[i] = self(self, i));
            }
        }
        return ans;
    };
    std::cout << aa(aa, n);
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    if (OJ_NAME != "AtCoder")
        std::cin >> T;
    while (T--) nhir();
    return 0;
}
