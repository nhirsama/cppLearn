//B - Two Colors Card Game
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
    i64 n,ans = 0;
    cin>>n;
    unordered_map<string ,i64> mp;
    while(n--){
        string s;
        cin>>s;
        if(mp.find(s) != mp.end()){
            mp[s]++;
        }
        else mp[s] = 1;
    }
    i64 m;
    cin>>m;
    while(m--){
        string s;
        cin>>s;
        if(mp.find(s) != mp.end()){
            mp[s]--;
        }
        else mp[s] = -1;
    }
    for(auto [x,y] : mp){
        ans = max(ans,1ll*y);
    }
    cout<<ans<<endl;
    return 0;
}
