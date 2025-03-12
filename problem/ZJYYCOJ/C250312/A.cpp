#include <bits/stdc++.h>
#define ll long long
#define PII pair<int,int>
using namespace std;

const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    function po = [&](int x) {
        ll res = 1, now = 26;
        while (x != 0) {
            if (x & 1) res = (now * res) % MOD;
            x = x >> 1;
            now = (now * now) % MOD;
        }
        return res;
    };
    cout << po(n) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
}