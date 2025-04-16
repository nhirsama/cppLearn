//  F. Skibidus and Slay
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
    i32 n;
    std::cin>>n;
    std::vector g(n,std::vector<i32>());
    std::vector<bool> ok(n);
    std::vector<i32> w(n);
    for(auto &i:w) {
        std::cin >>i;
        i--;
    }
    for(i32 i = 1;i<n;i++){
        i32 u,v;
        std::cin>>u>>v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto dfs = [&](auto && self,i32 u,i32 f)->void{
        std::map<i32,i32> m;
        m[w[u]]++;
        for(auto i:g[u]){
            //if(i == f) continue;
            m[w[i]]++;
            if(m[w[i]]>=2) ok[w[i]] = true;
            //self(self,i,u);
        }
        for(auto i:g[u]){
            if(i == f) continue;
            self(self,i,u);
        }
    };
    dfs(dfs,0,-1);
    for(auto i:ok) std::cout<<i;
    std::cout<<endl;
}

signed main() {
    IOS;
    i32 T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}