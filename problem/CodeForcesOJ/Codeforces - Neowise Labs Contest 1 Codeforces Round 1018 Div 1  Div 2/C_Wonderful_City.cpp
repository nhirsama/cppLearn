//  C. Wonderful City
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = int;
using pii = std::pair<i32, i32>;
constexpr int N = 1e5 + 10;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void nhir() {
    int n;
    std::cin>>n;
    std::vector g(n+1,std::vector<i32> (n+1));
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            std::cin>>g[i][j];
        }
    }
    std::vector<int> h(n+1),l(n+1);
    for(int i = 1;i<=n;i++) std::cin>>h[i];
    for(int i = 1;i<=n;i++) std::cin>>l[i];
    std::vector dph(n+1,std::vector<i64> (2,0x3f3f3f3f3f3f3f3f)),dpl(n+1,std::vector<i64> (2,0x3f3f3f3f3f3f3f3f));
    dph[1][0] = 0;
    dph[1][1] = h[1];
    for(i32 hh = 2;hh<=n;hh++){
        bool ok1 = true,ok2 = true,ok3 = true;
        for(i32 ll = 1;ll<=n;ll++){
            if(g[hh][ll] == g[hh-1][ll]) ok1 = false;
            if(g[hh][ll] == g[hh-1][ll]+1) ok2 = false;
            if(g[hh][ll]+1 == g[hh-1][ll]) ok3 = false;
        }
        if(ok1){
            dph[hh][0] = std::min(dph[hh][0],dph[hh-1][0]);
            dph[hh][1] = std::min(dph[hh][1],dph[hh-1][1]+h[hh]);
        }
        if(ok2){
            dph[hh][0] = std::min(dph[hh][0],dph[hh-1][1]);
        }
        if(ok3){
            dph[hh][1] = std::min(dph[hh][1],dph[hh-1][0]+h[hh]);
        }
    }
    i64 ans = std::min(dph[n][0],dph[n][1]);
    dpl[1][0] = 0;
    dpl[1][1] = l[1];
    for(i32 ll = 2;ll<=n;ll++){
        bool ok1 = true,ok2 = true,ok3 = true;
        for(i32 hh = 1;hh<=n;hh++){
            if(g[hh][ll] == g[hh][ll-1]) ok1 = false;
            if(g[hh][ll] == g[hh][ll-1]+1) ok2 = false;
            if(g[hh][ll]+1 == g[hh][ll-1]) ok3 = false;
        }
        if(ok1){
            dpl[ll][0] = std::min(dpl[ll][0],dpl[ll-1][0]);
            dpl[ll][1] = std::min(dpl[ll][1],dpl[ll-1][1]+l[ll]);
        }
        if(ok2){
            dpl[ll][0] = std::min(dpl[ll][0],dpl[ll-1][1]);
        }
        if(ok3){
            dpl[ll][1] = std::min(dpl[ll][1],dpl[ll-1][0]+l[ll]);
        }
    }
    ans+=std::min(dpl[n][0],dpl[n][1]);
    if(ans>0x3f3f3f3f3f3f3f3fll/2) ans = -1;
    std::cout<<ans<<endl;
}

signed main() {
    IOS;
    i32 T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}