//  C - Concat (X-th)
//  下午10:02
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"AtCoder"};

void nhir() {
    int64 n, k, x;
    std::cin >> n >> k >> x;
    std::vector<int64> jz;
    std::vector<std::string> s(n);
    for (auto &i: s)std::cin >> i;
    std::vector<std::string> ss;
    auto dfs = [&](auto &&self, int d, std::string ads) {
        if (d == k) {
            ss.push_back(ads);
            return;
        }
        for (auto &i: s) {
            self(self, d + 1, ads + i);
        }
    };
    dfs(dfs, 0, "");
    std::ranges::sort(ss);
    std::cout << ss[x - 1];
//    x--;
//    while (x) {
//        jz.push_back(x % n);
//        x /= n;
//    }
//    std::ranges::sort(s);
//    std::stack<std::string> ans;
//    for (int i = 0; i < jz.size(); i++) {
//        ans.push(s[jz[i]]);
//    }
//    for (auto i = jz.size(); i < k; i++) {
//        ans.push(s[0]);
//    }
//    while (!ans.empty()) {
//        std::cout << ans.top();
//        ans.pop();
//    }
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