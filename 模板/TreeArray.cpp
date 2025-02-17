#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
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