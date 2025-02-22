//P1873 [COCI 2011/2012 #5] EKO / 砍树
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 4e5 + 10;
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

ll n, m;
ll cf[N],sum[N];
int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    n = read();
    m = read();
    for (ll i = 0; i < n; i++) {
        ll x = read();
        cf[1]++;
        cf[x+1]--;
    }
    ll sum1 = 0;
    for (ll i = 1; i < N; i++) {
        sum1 += cf[i];
        sum[i] = sum[i-1]+sum1;
    }
    int l = 1, r = N;
    while (l < r) {
        ll mid = (l*1ll + r) >> 1;
        if (sum[N-1]-sum[mid] < m) {
            r = mid;
        } else {
            l = mid+1;
        }
    }
    cout << l-1 endl;
    return 0;
}
