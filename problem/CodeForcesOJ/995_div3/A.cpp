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
    int n;
    int aaans = 0,bans = 0;
    cin>>n;
    vector<pii> arr(n+1);
    for(int i = 1;i<=n;i++){
        cin>>arr[i].x;
    }
    for(int i = 1;i<=n;i++){
        cin>>arr[i].y;
    }
    for(int i = 1;i<n;i++){
        if(arr[i].x>arr[i+1].y) aaans+=arr[i].x,bans+=arr[i+1].y;
    }
    aaans+=arr[n].x;
    cout<<aaans-bans<<endl;
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
