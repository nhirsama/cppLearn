#define LOCAL
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define x first
#define y second
#define endl '\n'
#define space << ' '
typedef pair<int, int> pii;

void Solve() {
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll ans = a/(b+c+d)*3;
    a%=(b+c+d);
    ans+=(a>0);
    a-=b;
    ans+=(a>0);
    a-=c;
    ans+=(a>0);
    cout<<ans<<endl;
}

int main() {
    IOS
    #ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    //freopen("Code.out", "w", stdout);
    #endif
    int T;
    cin >> T;
    while (T--) {
        Solve();
    }
    return 0;
}
