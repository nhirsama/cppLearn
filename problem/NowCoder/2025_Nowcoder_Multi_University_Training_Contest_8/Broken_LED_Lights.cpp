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

std::string to_binary(int x) {
    std::string res;
    for (int i = 31; i >= 0; --i)
        if (x & (1 << i)) {
            res += '1';
            for (--i; i >= 0; --i)
                res += (x & (1 << i)) ? '1' : '0';
            break;
        }
    return res.empty() ? "0" : res;
}

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
//        std::cout << to_binary(v[i]) << endl;
    }
    std::set<int> R;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            R.insert(v[i] ^ v[j]);
        }
    }
    int ans = 21;
    for (int i = 0; i <= (1 << 7 * m); i++) {
        if (i & andv || ((orv | i) != orv)) continue;
        int cnt = __builtin_popcount(i);
        if (cnt >= ans) continue;
        [&]() {
            for (auto j: R) {
                if ((i & j) == 0) {
                    return;
                }
            }
            ans = cnt;
        }();
    }
    std::cout << ans << enld;
/*
// 根据1的个数启发式搜索只能得到76分。
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
std::ranges::sort(nex, std::greater());
auto dfs = [&](auto &&self, int sd, int kk, int ones) {
    if (ones >= ans) return;
    if (sd == nex.size()) {
        std::unordered_set<int> uns;
        for (auto i: v) {
            if (uns.find(kk & i) != uns.end()) {
                return;
            } else {
                uns.insert(kk & i);
            }
        }
        ans = ones;
        return;
    }
    if (cnt[nex[sd][0]] > n / 2) {
        self(self, sd + 1, kk, ones);
        self(self, sd + 1, kk | (1 << (nex[sd][1])), ones + 1);
    } else {
        self(self, sd + 1, kk | (1 << (nex[sd][1])), ones + 1);
        self(self, sd + 1, kk, ones);
    }

};
dfs(dfs, 0, 0, 0);
std::cout << ans << endl;
 */
/*
//    int basef = 0b111111111111111111111;
std::set<int> basss;
for(int i = 0;i<10;i++){
    for(int j = i+1;j<10;j++){
        basss.insert(base[i]^base[j]);
    }
}
int ans = 0x3f3f3f3f;
auto dfs = [&](auto &&self, int sd, int kk, int onen) -> bool {
    if (onen >= ans) return false;
    if (sd == m * 7) {
        std::unordered_set<int> uns;
        for (auto i: v) {
            if (uns.find(kk & i) != uns.end()) {
                return false;
            } else {
                uns.insert(kk & i);
            }
        }
        ans = std::min(ans, __builtin_popcount(kk));
        return true;
    }
    self(self, sd + 1, kk, onen);
    if (((orv >> sd) & 1) == 1 && ((andv >> sd) & 1) == 0) {
        self(self, sd + 1, kk | (1 << sd), onen + 1);
    }
    return false;
};
dfs(dfs, 0, 0, 0);
std::cout << ans << enld;
*/
//    for (int kk = 0; kk < (orv & andv); kk++) {
//        if (__builtin_popcount(kk) >= ans) continue;
//        bool ok = true;
//        std::unordered_set<int> uns;
//        for (auto i: v) {
//            if (uns.find(kk & i) != uns.end()) {
//                ok = false;
//                break;
//            } else {
//                uns.insert(kk & i);
//            }
//        }
//        if (ok) {
//            ans = std::min(ans, __builtin_popcount(kk));
////            std::cout << to_binary(kk) << endl;
//        }
//    }
//    std::cout << ans << enld;
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