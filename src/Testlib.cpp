#include <bits/stdc++.h>
using namespace std;

using ll = long long;

unordered_map<ll, int> memo;

int compute(int n, const vector<int>& pre, ll m) {
    if (m <= n) return pre[m];
    if (memo.count(m)) return memo[m];
    return memo[m] = compute(n, pre, m-1) ^ compute(n, pre, m/2);
}

void solve() {
    int n;
    ll l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    vector<int> pre(n + 1);
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i-1] ^ a[i-1];
    }
    ll k = l; // since l == r
    ll m = k / 2;
    memo.clear();
    cout << compute(n, pre, m) << '\n';
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