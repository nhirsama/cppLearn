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
    ll n,x,y,sum = 0;
    cin>>n>>x>>y;
    vector<ll> arr(n+1);
    for(int i = 1;i<=n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    sort(arr.begin()+1,arr.end());
    ll ans = 0;
    ll low = sum-y,upp = sum-x;
    if (low<0 && upp<0) {
        cout<<0<<endl;
        return ;
    }
    for(int i = 1;i<=n;i++){
        int l = lower_bound(arr.begin()+1,arr.end(),low-arr[i])-arr.begin();
        int r = upper_bound(arr.begin()+1,arr.end(),upp-arr[i])-arr.begin();
        if (r == n+1 && l == n+1) continue;
        r--;
        if (l == n+1) l--;
        ans+=r-l+1-(l<=i && i<=r);
    }
    cout<<ans/2<<endl;
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
