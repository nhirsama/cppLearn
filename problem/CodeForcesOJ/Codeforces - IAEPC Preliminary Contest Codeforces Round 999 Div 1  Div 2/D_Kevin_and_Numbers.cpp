//  D. Kevin and Numbers
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
    i32 n, m;
    std::cin >> n >> m;
    std::map<i32, i32> m1;
    for (i32 i = 0; i < n; i++) {
        i32 a;
        std::cin >> a;
        m1[a]++;
    }
    bool ok = true;
    auto f = [&](auto &&self, i32 v)-> void {
        if (v == 0) ok = false;
        if (m1[v]) m1[v]--;
        else if (v & 1) {
            i32 odd = v >> 1;
            i32 even = odd + 1;
            if (m1[odd]) m1[odd]--;
            else if (ok)self(self, odd);
            if (m1[even]) m1[even]--;
            else if (ok)self(self, even);
        } else {
            i32 odd = v >> 1;
            if (m1[odd] >= 2) m1[odd] -= 2;
            else if (m1[odd] == 1) {
                m1[odd]--;
                if (ok)self(self, odd);
            } else {
                if (ok)self(self, odd);
                if (ok)self(self, odd);
            }
        }
    };
    for (i32 i = 0; i < m; i++) {
        i32 a;
        std::cin >> a;
        if (ok) {
            f(f, a);
        }
    }
    for (auto [x,y]: m1) {
        if (y)ok = false;
    }
    if (ok) {
        std::cout << "Yes\n";
    } else std::cout << "No\n";
}

signed main() {
    IOS;
    i32 T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
