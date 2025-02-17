//P1972 [SDOI2009] HH的项链
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e6 + 10;
typedef long long int ll;
#define x first
#define y second
typedef pair<int, int> pii;

ll read() {
    ll ans = 0;
    char c = cin.get();
    while (c < '0' || c > '9') c = cin.get();
    while (c >= '0' && c <= '9') ans = (ans << 3) + (ans << 1) + (c ^ '0'), c = cin.get();
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

struct Node {
    int r, l, num;
} pr[N];

bool cmp(Node a, Node b) {
    return a.r < b.r;
}

int ans[N], next1[N];

int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    n = read();
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        arr[i] = read();
    }
    ll m;
    m = read();
    for (int i = 1; i <= m; i++) {
        pr[i].l = read();
        pr[i].r = read();
        pr[i].num = i;
    }
    sort(pr + 1, pr + m + 1, cmp);
    TreeArray count(n + 1);

    for (int i = 1, l = 1; i <= m; i++) {
        for (; l <= pr[i].r; l++) {
            count.update(l, 1);
            if (next1[arr[l]]) count.update(next1[arr[l]], -1);
            next1[arr[l]] = l;
        }
        ans[pr[i].num] = count.getsum(pr[i].r) - count.getsum(pr[i].l - 1);
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
