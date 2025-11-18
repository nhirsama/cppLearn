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
void nhir(){
    string s;
    cin>>s;
    i64 a = 0,b = 0;
    for(int i = 0;i<s.size()-1;i++){
        if(s[i] == '0' && s[i+1] == '1') a++;
        else if(s[i] == '1' && s[i+1] == '0') b++;
    }
    if(a>2 || b>2) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}
signed main() {
    IOS;
    int t;
    cin>>t;
    while(t--) nhir();
    return 0;
}
