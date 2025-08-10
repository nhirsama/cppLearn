//  C. Make it Equal
//  22:51
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"Codeforces"};

void nhir() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    std::multiset<int> b;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i] %= k;
        // a[i] = std::min(a[i], std::abs(k - a[i]));
    }
    for (int i = 0; i < n; i++) {
        int t;
        std::cin >> t;
        t %= k;
        b.insert(t);
    }
    std::ranges::sort(a);
    for (auto i: a) {
        if (b.find(i) != b.end()) {
            b.erase(b.find(i));
        } else {
            if (b.find(k - i) != b.end()) {
                b.erase(b.find(k - i));
            }
        }
    }
    if (b.size() == 0) {
        std::cout << "YES\n";
    } else std::cout << "NO\n";
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
