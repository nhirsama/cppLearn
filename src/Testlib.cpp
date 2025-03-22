#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long x, y;
        cin >> x >> y;
        long long z = x & y;
        if (z == 0) {
            cout << 0 << '\n';
            continue;
        }
        long long m = z & -z;
        long long k = m;
        if (((x + k) & (y + k)) == 0) {
            cout << k << '\n';
            continue;
        }
        k = (m << 1) - 1;
        if (((x + k) & (y + k)) == 0) {
            cout << k << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
    return 0;
}