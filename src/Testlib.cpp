#include<bits/stdc++.h>
#include<string>
using namespace std;
typedef long long ll;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;
const int N = 2e3 + 10;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

int a[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int b[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
set<pair<ll, ll> > vis;

void bfs(ll x, ll y) {
    int ans1 = 0, ans2 = 0;
    queue<pair<ll, ll> > q;
    q.emplace(x, y);
    vis.emplace(x, y);
    while (q.size()) {
        tie(x, y) = q.front();
        q.pop();
        if (x == y) {
            ans1 = 0, ans2 = 1;
            break;
        }
        ans2++;
        for (int i = 0; i < 8; i++) {
            ll xx = x + a[i];
            ll yy = y + b[i];
            if (gcd(xx, yy) > 1) {
                ans2++;
                if (vis.count(make_pair(xx, yy)))
                    continue;
                vis.insert(make_pair(xx, yy));
                q.emplace(xx, yy);
            }
        }
        if (!ans1)ans1 = ans2;
    }
    int tp = gcd(ans1, ans2);
    ans1 /= tp, ans2 /= tp;
    printf("%d/%d\n", ans1, ans2);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll x, y;
        cin >> x >> y;
        bfs(x, y);
    }
}
