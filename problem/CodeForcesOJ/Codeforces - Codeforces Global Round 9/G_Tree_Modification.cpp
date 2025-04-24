//  G. Tree Modification
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
    std::vector tree(n,std::vector<int> ());
    for(int i = 1;i<n;i++){
        int u,v;
        std::cin>>u>>v;
        u--,v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    std::vector<int> colour(n);
    colour[0] = 1;
    auto dfs = [&](auto && self,int u,int f)->void{
        colour[u] = 3-colour[f];
        for(auto i:tree[u]){
            if(i == f){
                continue;
            }
            self(self,i,u);
        }
    };
    dfs(dfs,0,0);
    int cnt[3]{};
    for(auto i:colour) cnt[i]++;
    std::cout<<std::min(cnt[1],cnt[2])-1<<endl;
}

signed main() {
    IOS;
    i32 T = 1;
    while (T--) nhir();
    return 0;
}