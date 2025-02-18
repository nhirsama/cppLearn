#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e5 + 10;
constexpr int NN = 1e5+5;
typedef long long int ll;
#define x first
#define y second
#define endl << '\n'
#define space << ' ' <<
typedef pair<int, int> pii;
constexpr int mod = 998244353;
void Func() {
    int n;
    ll ans = 0;
    cin >> n;
    vector<ll> v(n + 1);
    int one = 0,tow =0 ;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] == 1) {
            one++;
        }
        else if (v[i] == 2) {
            tow += one+tow;
            tow %= mod;
        }
        else {
            ans+=tow;
            ans %= mod;
        }
    }
    cout << ans % mod endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Func();
    }
    return 0;
}
