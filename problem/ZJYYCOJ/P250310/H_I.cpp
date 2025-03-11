//I. 优美的排列
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 20;
typedef long long int ll;
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define x first
#define y second
#define endl '\n'
#define space << ' '
typedef pair<int, int> pii;
ll n;
inline ll read() {
    ll ans = 0;
    bool flag = false;
    char c = cin.get();
    while (c < '0' || c > '9') {
        if (c == '-') flag = true;
        c = cin.get();
    }
    while (c >= '0' && c <= '9') ans = (ans << 3) + (ans << 1) + (c ^ '0'), c = cin.get();
    if (flag) return -ans;
    return ans;
}
bool st[N];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    IOS
    while(cin>>n){
        ll ans = 0;
        auto dfs = [&] (auto self,int w){
            if(w == n){
                ans++;
                return;
            }
            for(int i = 1;i<=n;i++){
                if(st[i]) continue;
                if(i%(w+1) == 0 || (w+1)%i == 0){
                    st[i] = true;
                    self(self,w+1);
                    st[i] = false;
                }
            }
        };
        dfs(dfs,0);
        cout<<ans<<endl;
    }
    return 0;
}
