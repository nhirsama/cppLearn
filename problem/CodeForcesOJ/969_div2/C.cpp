#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define x first
#define y second
#define endl '\n'
#define space << ' '
typedef pair<int, int> pii;

void Solve() {
    ll n,b,c;
    cin>>n>>b>>c;
    ll m = gcd(b,c);
    vector<ll> arr(2*n+1);
    for (int i = 1;i<=n;i++){
        cin>>arr[i];
        arr[i]%=m;
    }
    sort(arr.begin()+1,arr.begin()+n+1);
    for(int i = 1;i<=n;i++){
        arr[n+i] = arr[i]+m;
    }
    ll ans = arr[n]-arr[1];
    for(int i = 1;i<=n;i++)ans = min(arr[n+i-1]-arr[i],ans);
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
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
