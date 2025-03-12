#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll merge_and_count(vector<pair<ll, ll>>& intervals) {
    if (intervals.empty()) return 0;
    sort(intervals.begin(), intervals.end());
    ll res = 0;
    ll cur_left = intervals[0].first;
    ll cur_right = intervals[0].second;
    for (size_t i = 1; i < intervals.size(); ++i) {
        if (intervals[i].first > cur_right + 1) {
            res += cur_right - cur_left + 1;
            cur_left = intervals[i].first;
            cur_right = intervals[i].second;
        } else {
            cur_right = max(cur_right, intervals[i].second);
        }
    }
    res += cur_right - cur_left + 1;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<ll> x(n);
        vector<int> r(n);
        for (int i = 0; i < n; ++i) cin >> x[i];
        for (int i = 0; i < n; ++i) cin >> r[i];
        int max_k = 0;
        for (int ri : r) max_k = max(max_k, ri);
        vector<vector<pair<ll, ll>>> intervals(max_k + 1);
        for (int i = 0; i < n; ++i) {
            ll xi = x[i];
            int ri = r[i];
            ll ri_sq = (ll)ri * ri;
            for (int k = 0; k <= ri; ++k) {
                ll k_sq = (ll)k * k;
                ll s_sq = ri_sq - k_sq;
                if (s_sq < 0) continue;
                double s = sqrt(s_sq);
                ll left = ceil(xi - s);
                ll right = floor(xi + s);
                if (left > right) continue;
                intervals[k].emplace_back(left, right);
            }
        }
        ll ans = 0;
        for (int k = 0; k <= max_k; ++k) {
            if (intervals[k].empty()) continue;
            ll cnt = merge_and_count(intervals[k]);
            ans += (k == 0) ? cnt : 2 * cnt;
        }
        cout << ans << '\n';
    }
    return 0;
}