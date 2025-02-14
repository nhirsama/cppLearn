//P11450 [USACO24DEC] Farmer John's Cheese Block B
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e3+10;
typedef long long int ll;
#define x first
#define y second
typedef pair<int, int> pii;
ll n,q;
int xx[N][N],yy[N][N],zz[N][N];
int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    ll ans = 0;
    cin >> n >> q;
    for (ll i = 1; i <= q; i++) {
        int x,y,z;
        scanf("%d%d%d", &x,&y,&z);
        xx[y][z]++;
        yy[x][z]++;
        zz[x][y]++;
        if(xx[y][z] == n) ans++;
        if(yy[x][z] == n) ans++;
        if(zz[x][y] == n) ans++;
        cout << ans << endl;
    }
    return 0;
}
