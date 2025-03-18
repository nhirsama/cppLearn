#include <bits/stdc++.h>
using namespace std;

// using ll = long long;
using int = long long;
ll min_cost(ll s) {
    if (s == 0) return 0;
    ll k = 0;
    while ((k + 1) * (k + 2) / 2 <= s) {
        k++;
    }
    ll total = k * (k + 1) / 2;
    ll remaining = s - total;
    if (remaining == 0) {
        return (1LL << (k + 1)) - 2;
    } else if (remaining > k) {
        return ((1LL << (k + 1)) - 2) + (1LL << remaining);
    } else {
        ll removed = k + 1 - remaining;
        return ((1LL << (k + 2)) - 2) - (1LL << removed);
    }
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        ll x, y;
        cin >> x >> y;
        if (x == y) {
            cout << 0 << '\n';
            continue;
        }
        int xcnt = 0, ycnt = 0;
        while ((x >> xcnt) != (y >> ycnt)) {
            if ((x >> xcnt) > (y >> ycnt)) {
                xcnt++;
            } else ycnt++;
        }
        ll s = xcnt + ycnt;
        ll cost = min_cost(s);

        cout << cost << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
