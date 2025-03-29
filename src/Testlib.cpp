#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string a, b;
    cin >> n >> a >> b;

    int total_zero = 0;
    for (char c : a) total_zero += (c == '0');
    for (char c : b) total_zero += (c == '0');

    if (total_zero < n) {
        cout << "NO\n";
        return;
    }

    if (a[0] == '0' || b[1] == '0') {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}