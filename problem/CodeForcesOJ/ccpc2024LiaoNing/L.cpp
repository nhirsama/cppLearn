#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    // i64 n, ans = 0;
    // cin >> n;
    // i64 dis = n - 2024, base4 = 4, base1 = 100;
    // cout << n - 114514 << " ";
    // while (true) {
    //     if (!(dis / base4) && !(dis / base1)) break;
    //     ans += dis / base4 - dis / base1;
    //     base1 *= 100;
    //     base4 *= 100;
    // }
    // cout << ans + 2024 << "\n";
    i64 n;
    cin >> n;

    auto check = [&](i64 x) {
        i64 dis = x, base4 = 4, base1 = 100, cmp = 0;
        while (true) {
            if (!(dis / base4) && !(dis / base1)) break;
            cmp += dis / base4 - dis / base1;
            base1 *= 100;
            base4 *= 100;
        }
        return cmp - 491 + 2024 >= x - n;
    };

    i64 l = -1, r = 3e18 + 1;
    while (l + 1 < r) {
        i64 mid = l + (r - l >> 1);


        if (check(mid)) l = mid;
        else r = mid;
    }
    // if (n % 3 == 0)--l;
    i64 base4 = 4, base1 = 100;
    while (true) {
        if (l % base4) {
            break;
        }
        if (!(l % base4) && !(l % base1)) {
            base1 *= 100;
            base4 *= 100;
            continue;
        }
        if (!(l % base4) && l % base1) {
            --l;
            break;
        }
    }
    cout << l << "\n";
}

void IOS() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    IOS();
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
