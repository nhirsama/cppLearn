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

void nhir() {
    i32 n;
    cin>>n;
    vector<i32> v(n+1);
    for(i32 i=1;i<=n;i++)cin>>v[i];
    vector<i32> v2(10);
    for(i32 i=1;i<=n;i++){
        v2[v[i]]++;
        if(v2[0] >= 3 && v2[1] >=1 && v2[3]>=1&&v2[2]>=2 && v2[5]>=1){
            cout<<i<<endl;
            return ;
        }
    }
    cout<<0<<endl;
}

signed main() {;
    IOS;
    i32 T;
    cin >> T;
    while (T--) nhir();
    return 0;
}
