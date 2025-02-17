//P10589 楼兰图腾
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define x first
#define y second
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

int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    TreeArray tr(n);
    vector<ll> g(n + 1), l(n + 1), arr(n + 1);
    for (ll i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (ll i = 1; i <= n; i++) {
        l[i] = tr.getsum(arr[i] - 1);
        g[i] = tr.getsum(n) - tr.getsum(arr[i]);
        tr.update(arr[i], 1);
    }
    tr = TreeArray(n);
    ll ansA = 0, ansB = 0;
    for (ll i = n; i; i--) {
        ansA += l[i] * tr.getsum(arr[i] - 1);
        ansB += g[i] * (tr.getsum(n) - tr.getsum(arr[i]));
        tr.update(arr[i], 1);
    }
    cout << ansB << ' ' << ansA << endl;
    return 0;
}
