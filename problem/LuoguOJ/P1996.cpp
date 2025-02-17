//P1996 约瑟夫问题
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5+10;
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
int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m;
    cin>>n>>m;
    TreeArray tree(n);
    return 0;
}
