//模板
#include <bits/stdc++.h>
using namespace std;
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef pair<i32, i32> pii;
constexpr int N = 6e6;
constexpr int mod = 998244353;
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all1(x) (x).begin() + 1, (x).end()
#define int long long
vector<i64> niyuan(N+1);
i64 power(i64 a, i64 b, i64 p) {
    i64 res = 1;
    for (; b; b /= 2, a = 1LL * a * a % p) {
        if (b % 2) {
            res = 1LL * res * a % p;
        }
    }
    return res;
}
void nhir() {
    i64 a;
    cin>>a;
    cout<<3ll*power(a,mod-2,mod)*niyuan[a]%mod<<endl;


}

signed main() {;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
    }
    IOS;
    for (i64 i= 1;i<=N;i++) {
        niyuan[i] = (power(i*i%mod,mod-2,mod)+niyuan[i-1])%mod;
    }
    i32 T;
    cin >> T;
    while (T--) nhir();
    return 0;
}
