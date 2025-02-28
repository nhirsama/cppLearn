#include <bits/stdc++.h>
using namespace std;

bool check(const string &s, const vector<int>& a, int n, int k, int x) {
    vector<int> forbidden;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'R' && a[i] > x) {
            forbidden.push_back(i);
        }
    }
    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + ((s[i] == 'B' && a[i] > x) ? 1 : 0);
    }
    vector<pair<int, int>> blocks;
    int prev = -1;
    for (int pos : forbidden) {
        int l = prev + 1;
        int r = pos - 1;
        if (l <= r) {
            blocks.emplace_back(l, r);
        }
        prev = pos;
    }
    int l = prev + 1;
    int r = n - 1;
    if (l <= r) {
        blocks.emplace_back(l, r);
    }
    int cnt = 0;
    for (auto& [bl, br] : blocks) {
        if (prefix[br + 1] - prefix[bl] > 0) {
            cnt++;
        }
    }
    return cnt <= k;
}

void Solve() {
    int n, k;
    string s;
    vector<int> a;
    cin >> n >> k >> s;
    a.resize(n);
    int right =0 ;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        right = max(right,a[i]);
    }
    int left = 0;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (check(s, a, n, k, mid)) {
            right = mid;
        } else {
            left = mid+1;
        }
    }
    cout << left << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        Solve();
    }
    return 0;
}