//模板
#include <bits/stdc++.h>
using namespace std;
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef pair<i32, i32> pii;
constexpr int N = 1e5 + 10;
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all1(x) (x).begin() + 1, (x).end()
#define int long long

signed main() {
    IOS;
    i64 n;
    cin>>n;
    vector<i32> arr(n+1);
    for(int i = 1;i<=n;i++) cin>>arr[i];
    sort(all1(arr));
    i64 ans =0;
    for(int i = 1;i<=n;i++){
        if(i&1) ans+=arr[i];
        else ans-=arr[i];
    }
    cout<<ans<<endl;
    return 0;
}
