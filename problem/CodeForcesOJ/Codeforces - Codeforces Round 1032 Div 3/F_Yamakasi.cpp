//  F. Yamakasi
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

struct ST {
    const int n, k;
    std::vector<int> in1, in2;
    std::vector<std::vector<int> > Max;

    ST(int n) : n(n), in1(n + 1), in2(n + 1), k(std::__lg(n)) {
        Max.resize(k + 1, std::vector<int>(n + 1));
    }

    void init() {
        for (int i = 1; i <= n; i++) {
            Max[0][i] = in1[i];
        }
        for (int i = 0, t = 1; i < k; i++, t <<= 1) {
            const int T = n - (t << 1) + 1;
            for (int j = 1; j <= T; j++) {
                Max[i + 1][j] = std::max(Max[i][j], Max[i][j + t]);
            }
        }
    }

    int getMax(int l, int r) {
        if (l > r) {
            std::swap(l, r);
        }
        int k = std::__lg(r - l + 1);
        return std::max(Max[k][l], Max[k][r - (1 << k) + 1]);
    }
};

void nhir() {
    i32 n, s, x;
    std::cin >> n >> s >> x;
    std::vector<i32> v(n);
    for (i32 &i: v) {
        std::cin >> i;
    }
    i32 ans = 0;
    i32 i = 0;
    while (i < n) {
        while (i < n && v[i] > x) i++;
        i32 j = i;
        while (j < n && v[j] <= x) j++;
        std::map<i32, i32> cnt;
        i32 sum = 0;
        cnt[0] = 1;
        i32 res = 0;
        for (i32 k = i; k < j; k++) {
            sum += v[k];
            auto it = cnt.find(sum - s);
            if (it != cnt.end()) res += it->second;
            cnt[sum]++;
        }
        i32 cntx = 0;
        i32 t = i;
        while (t < j) {
            if (v[t] == x) {
                t++;
            } else {
                i32 tt = t;
                while (tt < j && v[tt] < x) tt++;
                std::map<i32, i32> cnt2;
                i32 summ = 0;
                cnt2[0] = 1;
                for (i32 k = t; k < tt; k++) {
                    summ += v[k];
                    auto it = cnt2.find(summ - s);
                    if (it != cnt2.end()) cntx += it->second;
                    cnt2[summ]++;
                }
                t = tt;
            }
        }
        ans += res - cntx;
        i = j;
    }
    std::cout << ans << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
