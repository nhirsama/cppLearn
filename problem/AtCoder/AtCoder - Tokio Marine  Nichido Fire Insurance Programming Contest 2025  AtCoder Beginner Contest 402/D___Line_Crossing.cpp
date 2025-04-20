//  D - Line Crossing
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
    int n,m;
    std::cin>>n>>m;
    std::map<int,int> mp;
        for(int i = 0;i<m;i++){
            int a,b;
            std::cin>>a>>b;
            if(a == n && b!=1) a = 0;
            if(b == n && a!=1) b = 0;
            mp[a+b]++;
        }
    long long ans = 0;
    for(auto [x,y]:mp){
        ans+=y*(m-y);
    }
    std::cout<<ans/2<<endl;
}

signed main() {
    IOS;
    i32 T = 1;
    while (T--) nhir();
    return 0;
}