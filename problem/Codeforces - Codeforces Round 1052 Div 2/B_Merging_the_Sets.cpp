//  B. Merging the Sets
//  22:12
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"Codeforces"};

void nhir() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int> > v(n);
    std::vector<int> cnt(m);
    for (int i = 0; i < n; i++) {
        int t;
        std::cin >> t;
        while (t--) {
            int a;
            std::cin >> a;
            a--;
            v[i].push_back(a);
            cnt[a]++;
        }
    }
    for (auto i: cnt) {
        if (i == 0) {
            std::cout << "NO\n";
            return;
        }
    }
    int tot = 0;
    for (int i = 0; i < n; i++) {
        [&]() {
            for (auto j: v[i]) {
                if (cnt[j] == 1) return;
            }
            tot++;
        }();
    }
    if (tot >= 2) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
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