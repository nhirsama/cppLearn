//P2068 统计和
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define x first
#define y second
#define endl << '\n'
#define space << ' ' <<
typedef pair<int, int> pii;

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

int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, w;
    n = read();
    w = read();
    TreeArray tree(n);
    while (w--) {
        char x;
        int a, b;
        cin >> x;
        a = read();
        b = read();
        if (x == 'x') tree.update(a, b);
        else cout << tree.getsum(b) - tree.getsum(a - 1) endl;
    }
    return 0;
}
