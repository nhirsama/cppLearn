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
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll>arr(m+1),brr(k+1);
    set<ll> s;
    for(int i = 1;i<=m;i++){
        cin>>arr[i];
    }
    for(int i = 1;i<=k;i++){
        cin>>brr[i];
        s.insert(brr[i]);
    }
    for (int i = 1;i<=m;i++) {
        if ((s.find(arr[i]) == s.end() && n-1 == k) || n==k) {
            cout<<1;
        }
        else cout<<0;
    }
    cout<<endl;
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
