//  F. Counting Necessary Nodes
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = int;
using pii = std::pair<i32, i32>;
constexpr int N = 1e5 + 10;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
auto fun(i32 l,i32 r,const i32 &L,const i32 &R,std::vector<pii> &v){
    if(R<=l || r<=L) return;
    if(L<=l && r<=R){
        v.push_back({l,r});
        return;
    }
    fun(l,(l+r)>>1,L,R,v);
    fun((l+r)>>1,r,L,R,v);
}
void nhir() {
    i32 l1,r1,l2,r2;
    std::cin>>l1>>r1>>l2>>r2;
    i64 ans = 0;
    std::vector<pii> h,z;
    fun(0,1<<25,l1,r1,h);
    fun(0,1<<25,l2,r2,z);
    for(auto [hl,hr] : h){
        for(auto [zl,zr] : z){
            i32 a = hr-hl,b = zr-zl;
            ans += std::max(a,b)/std::min(a,b);
        }
    }
    std::cout<<ans<<endl;
}

signed main() {
    IOS;
    i32 T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}