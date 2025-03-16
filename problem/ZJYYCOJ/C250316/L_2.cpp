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
bool cmp(pii a,pii b) {
    return sqrt(a.x*a.x + a.y*a.y)<sqrt(b.x*b.x+b.y*b.y);
}
signed main() {
    IOS;
    i64 n,ans=0;
    cin>>n;
    vector<pii> r(n+1),b(n+1);
    for(int i=1;i<=n;i++){
        cin>>r[i].x>>r[i].y;
    }
    for(int i=1;i<=n;i++){
        cin>>b[i].x>>b[i].y;
    }
    sort(r.begin()+1,r.end(),cmp);
    sort(b.begin()+1,b.end(),cmp);

    for(int len=0;len<n;len++) {
        vector<bool> st(n+1,0);
        i64 tempans = 0;
        for(int i=1+len;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(st[j]) continue;
                if(r[i].x<b[j].x && r[i].y<b[j].y){
                    st[j]=1;
                    tempans++;
                    break;
                }
            }
        }
        for(int i=1;i<=len;i++){
            for(int j=1;j<=n;j++){
                if(st[j]) continue;
                if(r[i].x<b[j].x && r[i].y<b[j].y){
                    st[j]=1;
                    tempans++;
                    break;
                }
            }
        }
        ans = max(ans,tempans);
    }
    cout<<ans<<endl;
    return 0;
}
