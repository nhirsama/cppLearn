//  P12642 [KOI 2024 Round 1] 加倍
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

struct num {
    i32 v;
    i32 pow;

    num() {
        pow = 0;
        v = 0;
    }

    num(i32 __v) {
        pow = 0;
        v = __v;
        while (!(v & (1ll << 40))) {
            pow--;
            v <<= 1;
        }
    }

    i32 get(const num &t) {
        if (t.pow < this->pow) return 0;
        if (t.pow == this->pow && t.v <= this->v) return 0;
        i32 res = t.pow - this->pow;
        if (t.v > this->v) res++;
        this->pow += res;
        return res;
    }
};

void nhir() {
    i32 n;
    std::cin >> n;
    std::vector<num> v(n);
    for (i32 i = 0; i < n; i++) {
        i32 t;
        std::cin >> t;
        v[i] = num(t);
    }
    i32 ans = 0;
    for (i32 i = 1; i < n; i++) {
        ans += v[i].get(v[i - 1]);
    }
    std::cout << ans << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    // std::cin >> T;
    while (T--) nhir();
    return 0;
}
