//C
#include <bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long int i64;
typedef int i32;
typedef short i16;
typedef char i8;
typedef pair<i32, i32> pii;
constexpr int N = 1e5 + 10;
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all1(x) (x).begin() + 1, (x).end()
#define int long long

void nhir() {
    i64 n;
    cin >>n;
    vector<i64> arr(n+1);
    for(i32 i = 1;i<=n;i++){
        cin>>arr[i];
    }
    set<i32> a,b;
    vector<i64> dp1(n+1),dp2(n+1);
    for(i32 i = 1;i<=n;i++){
        a.insert(arr[i]);
        dp1[i] = a.size();
    }
    for(i32 i = n;i;i--){
        b.insert(arr[i]);
        dp2[i] = b.size();
    }
    i64 ans = 0;
    for(int i = 1;i<n;i++){
        ans = max(ans,dp1[i]+dp2[i+1]);
    }
    cout<<ans<<endl;
}

signed main() {
    IOS;
    i32 T = 1;
    while (T--) nhir();
    return 0;
}
