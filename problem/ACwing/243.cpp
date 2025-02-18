//模板
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define x first
#define y second
#define endl << '\n'
#define space << ' ' <<
typedef pair<int, int> pii;

inline ll read() {
    ll ans = 0;
    bool flag = false;
    char c = cin.get();
    while (c < '0' || c > '9') {
        if (c == '-') flag = true;
        c = cin.get();
    }
    while (c >= '0' && c <= '9') ans = (ans << 3) + (ans << 1) + (c ^ '0'), c = cin.get();
    if (flag) return -ans;
    return ans;
}

class TreeArray {
public:
    vector<ll> tree;
    int size;

    TreeArray(ll n) {
        size = n;
        tree = vector<ll>(n + 1, 0);
    }

    static ll lowbit(ll x) {
        return x & -x;
    }

    ll getsum(ll x) const {
        ll sum = 0;
        while (x) {
            sum += tree[x];
            x -= lowbit(x);
        }
        return sum;
    }

    void update(ll x, ll k) {
        for (ll i = x; i <= size; i += lowbit(i)) {
            tree[i] += k;
        }
    }
};

int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    TreeArray tr1(n), tr2(n);
    vector<ll> arr(n + 1);
    for (ll i = 1; i <= n; i++) {
        arr[i] = read();
    }
    for (ll i = 1; i <= n; i++) {
        ll d = arr[i]-arr[i-1];
        tr1.update(i, d);
        tr2.update(i, i * d);
    }
    for (ll i = 1; i <= m; i++) {
        ll l, r;
        char c;
        cin >> c;
        if (c == 'Q') {
            l = read();
            r = read();
            cout << (tr1.getsum(r) * (r + 1) - tr2.getsum(r)) - (tr1.getsum(l - 1) * (l) - tr2.getsum(l - 1)) endl;
        } else {
            ll x;
            l = read();
            r = read();
            x = read();
            tr1.update(l,x);
            tr2.update(l, l * x);
            tr1.update(r + 1, -x);
            tr2.update(r + 1, -x * (r+1));
        }
    }
    return 0;
}
