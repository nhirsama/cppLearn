#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll ans;

struct node {
    ll a, b, n;
};

int main() {
    ll n;
    cin >> n;
    vector<node> arr(n + 1),brr(n+1);
    vector<bool> st(n + 1);
    for (int i = 1; i <= n; i++) {
        ll a, b;
        cin >> a >> b;
        arr[i] = {a, b, i};
        brr[i] = arr[i];
    }
    ll cnt = 0;
    sort(arr.begin() + 1, arr.end(), [](node &a, node &b) { return a.a < b.a; });
    sort(brr.begin() + 1, brr.end(), [](node &a, node &b) { return a.b < b.b; });
    int ptr = 1;
    for (int i = 1; i <= n; i++) {
        if (st[arr[i].n]) continue;
        if (cnt >= arr[i].a) {
            cnt++;
            st[arr[i].n] = true;
        } else {
            for (;ptr<=n;ptr++) {
                if (!st[brr[ptr].n]) {
                    ans+=brr[ptr].b;
                    cnt++;
                    st[brr[ptr].n] = true;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
}
