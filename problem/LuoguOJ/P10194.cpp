//P10194 [USACO24FEB] Milk Exchange G
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define x first
#define y second
#define endl '\n'
#define space << ' '
typedef pair<int, int> pii;

int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m;
    ll sum = 0;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> arr(n), ind(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') ind[i - 1 >= 0 ? i - 1 : n - 1]++;
        else ind[i + 1 < n ? i + 1 : 0]++;
    }
    ll ans = 0;
    stack<int> sta;
    vector<bool> st(n, false);
    auto dfs = [&](auto self, auto u) -> ll {
        if (st[u]) return 0;
        st[u] = true;
        ll summ = 0;
        summ += arr[u];
        if (s[u] == 'L') {
            int v = u - 1 >= 0 ? u - 1 : n - 1;
            --ind[v];
            if (ind[v] == 0) {
                return summ + self(self, v);
            }
        } else {
            int v = u + 1 < n ? u + 1 : 0;
            --ind[v];
            if (ind[v] == 0) {
                return summ + self(self, v);
            }
        }
        return summ;
    };
    for (int i = 0; i < n; i++) {
        if (ind[i] == 0 && !st[i]) {
            ans += min(dfs(dfs, i), m);
        }
    }

    cout << sum - ans << endl;
    return 0;
}
