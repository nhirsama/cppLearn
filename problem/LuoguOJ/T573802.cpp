//T573802 [语言月赛 202502] 蛋挞烤制
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5+10;
typedef long long int ll;
#define x first
#define y second
typedef pair<int, int> pii;
int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    ll egg,milk,tart;
    ll e,m,t;

    cin>>egg>>milk>>tart;
    cin>>e>>m>>t;
    ll v = egg*e+milk*m;
    int aa=v/tart;
    if(aa%v)aa++;
    int ans = aa/t;
    if(aa%t)ans++;
    cout<<ans<<endl;
    return 0;
}
