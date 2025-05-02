#include <bits/stdc++.h>
using namespace std;

int power(int a, int b, int p) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res % p;
}

void solve() {
    int n, k, m, q;
    vector<bool> st(10005);
    cin >> n >> k >> m >> q;
    while (m--) {
        int x;
        std::cin >> x;
        for (int i = 1; i <= k; i++) {
            st[power(x, i, n)] = true;
        }
    }
    while (q--) {
        int y;
        std::cin >> y;
        bool ans = true;
        for (int i = 1; i <= k; i++) {
            ans &= st[power(y, i, n)];
            if (!ans) break;
        }
        std::cout << ans << ' ';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while (T--) solve();
}
