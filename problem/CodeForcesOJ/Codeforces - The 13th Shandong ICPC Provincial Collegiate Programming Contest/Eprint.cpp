#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll INF = 4e17;

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        ll n, k, m, a, b;
        cin >> n >> k >> m >> a >> b;
        map<ll, ll> mp;
        ll ans = INF;
        queue<ll> q;
        q.push(n);
        mp[n] = 0;
        while (q.size()) {
            auto x = q.front();
            q.pop();
            if (x % m == 0) {
                cout << mp[x];
                break;
            }
            q.push(x / k);
            mp[x / k] = mp[x] + b;
            for (int i = 0; i < k; ++i) {
                q.push(x * k + i);
                mp[x * k + i] = mp[x] + a;
            }
        }
        // for (auto &[x,y]: mp) {
        //     cout << x << " " << y << "\n";
        // }
    }
}
