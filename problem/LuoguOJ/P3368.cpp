//P3368 【模板】树状数组 2
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define x first
#define y second
typedef pair<int, int> pii;

ll read() {
    ll ans = 0;
    bool flag = false;
    char c = cin.get();
    while (c < '0' || c > '9') {
        if (c == '-') flag = true;
        c = cin.get();
    }
    while (c >= '0' && c <= '9') ans = (ans << 3) + (ans << 1) + (c ^ '0'), c = cin.get();
    if (flag)return -ans;
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
    n = read();
    m = read();
    vector<ll> a(n + 1);
    TreeArray tree(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = read();
    }
    for (int i = 1; i <= n; i++) {
        tree.tree[i] = a[i] - a[i - tree.lowbit(i)];
    }
    for (int i = 1; i <= m; i++) {
        int aa;
        aa = read();
        if (aa == 1) {
            ll x,y, k;
            x = read();
            y = read();
            k = read();
            tree.update(x, k);
            tree.update(y + 1, -k);
        } else {
            ll x;
            x = read();
            cout << tree.getsum(x) << endl;
        }
    }
    return 0;
}
