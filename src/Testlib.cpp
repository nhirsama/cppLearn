//  Broken LED Lights
//  下午12:15
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"NowCoder"};
constexpr int base[] = {
        0b1111110, 0b0110000, 0b1101101, 0b1111001, 0b0110011, 0b1011011, 0b1011111, 0b1110000, 0b1111111,
        0b1111011};

void nhir() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> v(n);
    int orv = 0, andv = ~0;
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < m; j++) {
            v[i] |= base[(s[m - j - 1] ^ 48)] << (((j << 3) - j));
        }
        orv |= v[i];
        andv &= v[i];
    }
    std::vector<int> cnt(21);
    for (auto i: v) {
        for (int j = 0; j < 21; j++) {
            cnt[j] += (i >> j) & 1;
        }
    }
    std::vector<std::array<int, 2>> nex;
    for (int i = 0; i < 21; i++) {
        int t = cnt[i] * (n - cnt[i]);
        if (t) nex.push_back({t, i});
    }
    int ans = 21;
    std::set<int> R;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            R.insert(v[i] ^ v[j]);
        }
    }
    std::ranges::sort(nex, std::greater());
    auto dfs = [&](auto &&self, int sd, int kk, int ones) {
        if (ones >= ans) return;
        if (sd == nex.size()) {
            for (auto j: R) {
                if ((kk & j) == 0) {
                    return;
                }
            }
            ans = ones;
            return;
        }
        if (cnt[nex[sd][0]] > n / 2) {
            self(self, sd + 1, kk | (1 << (nex[sd][1])), ones + 1);
            self(self, sd + 1, kk, ones);
        } else {
            self(self, sd + 1, kk, ones);
            self(self, sd + 1, kk | (1 << (nex[sd][1])), ones + 1);
        }

    };
    dfs(dfs, 0, 0, 0);
    std::cout << ans << endl;
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