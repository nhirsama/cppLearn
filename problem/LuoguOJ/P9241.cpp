//P9241 [蓝桥杯 2023 省 B] 飞机降落
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int t;
    cin >> t;
    auto solve = []() {
        ll n;
        cin >> n;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<> > p;
        struct node {
            ll t, d, l;
        };
        vector<node> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i].t >> arr[i].d >> arr[i].l;
        }
        sort(arr.begin(), arr.end(), [](auto a, auto b)-> bool { return a.t < b.t; });
        long long t = 0;
        for (auto i: arr) {

            while (t <= i.t) {
                if (p.empty()) {
                    t = i.t;
                    break;
                }
                auto aa = p.top();
                p.pop();
                if (aa.first <= t)t += aa.second;
                else {
                    cout << "NO" << endl;
                    return;
                }
            }
            p.push({i.t + i.d, i.l});
        }
        while (p.empty()) {
            auto aa = p.top();
            p.pop();
            if (aa.first <= t)t += aa.second;
            else {
                cout << "NO" << endl;
                return;
            }
        }
        cout << "YES" << endl;
        return;
    };
    while (t--) {
        solve();
    }
    return 0;
}
