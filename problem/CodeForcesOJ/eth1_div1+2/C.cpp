
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define int long long
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define x first
#define y second
#define endl '\n'
#define space << ' '
typedef pair<int, int> pii;

void Solve() {
    int n;
    ll sum  =0,ans = 0;
    cin>>n;
    vector<ll> arr(n+1);
    for(int i = 1;i<=n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    ans = sum;
    while (n>1) {
        sum=0;
        for (int i = 1;i<n;i++) {
            arr[i] = arr[i+1]-arr[i];
            sum+=arr[i];
        }
        ans = max(abs(sum),ans);
        n--;
    }
    // for (int len = 1;len<n;len++) {
    //     sum = 0;
    //     for (int i = 1;i+len<=n;i++) {
    //         sum+=arr[i+len]-arr[i];
    //     }
    //     ans = max(ans,abs(sum));
    // }
    cout<<ans<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        Solve();
    }
    return 0;
}
