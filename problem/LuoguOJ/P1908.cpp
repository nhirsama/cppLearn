//P1908 逆序对
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 5e5 + 10;
typedef long long int ll;
#define x first
#define y second
#define endl << '\n'
#define space << ' '
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
        tree = vector<ll>(n+1,0);
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

int arr[N],unarr[N];
int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("inAndoutFile/P1908_11.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,ans =0;
    n = read();
    for (int i = 1; i <= n; i++) {
        arr[i] = read();
        unarr[i] = arr[i];
    }
    sort(unarr+1, unarr + n+1);
    int m = unique(unarr+1, unarr + n+1) - unarr -1;
    TreeArray tr(m);
    for (int i = 1; i <= n; i++) {
        arr[i] = lower_bound(unarr+1,unarr+m+1,arr[i])-unarr;
    }
    for (int i = n; i; i--) {
        ans += tr.getsum(arr[i]-1);
        tr.update(arr[i],1);
    }
    cout << ans;
    return 0;
}
