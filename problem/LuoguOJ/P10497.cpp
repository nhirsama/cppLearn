//P10497 [USACO03Open] Lost Cows
//244. 谜一样的牛
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define x first
#define y second
#define endl << '\n'
#define space << ' ' <<
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
    int n;
    n = read();
    TreeArray tree(n);
    for (int i = 1; i <= n; i++) {
        tree.tree[i] = tree.lowbit(i);
    }
    vector<int> ans(n + 1), h(n + 1);
    for (int i = 2; i <= n; i++) {
        h[i] = read();
    }
    for (int i = n; i; i--) {
        int a = h[i];
        int l = 1, r = n;
        while (l < r) {
            int m = (l + r) / 2;
            if (tree.getsum(m) > a) r = m;
            else l = m + 1;
        }
        ans[i] = l;
        tree.update(l, -1);
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] endl;
    }
    return 0;
}
