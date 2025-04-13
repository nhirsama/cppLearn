//
// Created by Origami on 25-4-13.
//
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr int mod = 1e9 + 7;

struct mat {
    i64 a[2][2]{0};

    mat operator*(const mat &b) const {
        mat res;
        for (int i = 0; i < 2; i++) {
            for (int k = 0; k < 2; k++) {
                for (int j = 0; j < 2; j++) {
                    res.a[i][j] = (res.a[i][j] + this->a[i][k] * b.a[k][j] % mod) % mod;
                }
            }
        }
        return res;
    }
};

mat qpow(mat base, long long b) {
    mat res;
    res.a[0][0] = res.a[1][1] = 1;
    for (; b; b >>= 1, base = base * base) {
        if (b & 1) res = res * base;
    }
    return res;
}

void solve() {
    long long m;
    i64 num[10]{0};
    std::cin >> m;
    mat ans;
    for (int i = 0; i < 10; i++) std::cin >> num[i];
    if (m == 1 && num[0]) {
        std::cout << 0 << std::endl;
        return;
    }
    for (int i = 1; i < 10; i++) {
        if (num[i] > 0) {
            ans.a[0][0] = i;
            num[i]--;
            m--;
            break;
        }
    }
    for (int i = 0; i < 10 && m; i++) {
        if (num[i] > 0) {
            if (num[i] >= m) {
                ans.a[0][1] = i;
                mat base;
                base.a[0][0] = 10;
                base.a[1][0] = base.a[1][1] = 1;
                ans = ans * qpow(base, m);
                break;
            } else {
                m -= num[i];
                ans.a[0][1] = i;
                mat base;
                base.a[0][0] = 10;
                base.a[1][0] = base.a[1][1] = 1;
                ans = ans * qpow(base, num[i]);
            }
        }
    }
    std::cout << ans.a[0][0] % mod << std::endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) solve();
}

/*
8
3 1 0 0 0 3 0 0 0 0 0
1 2 0 0 0 0 0 0 0 0 0
4 0 1 1 1 3 0 0 0 0 0
5 1 0 0 0 0 2 0 0 0 2
9 10 1 0 0 0 5 0 0 0 2
100 100 0 0 0 0 0 0 0 0 0
17 0 17 0 0 0 0 0 0 0 0
1 1 0 0 0 0 0 1 0 0 0
999300007
33333334
33333334
*/
