//  C - Dislike Foods
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
    std::vector g(n+5,std::vector<int>());
    std::vector <int> rd(m+5);
    for(int i = 1;i<=m;i++){
        int k;
        std::cin>>k;
        for(int j = 0;j<k;j++){
            int a;
            std::cin>>a;
            g[--a].push_back(i);
            rd[i]++;
        }
    }
    int cnt = 0;
    for(int i = 1;i<=n;i++){
        int t;
        std::cin>>t;
        for(auto tt:g[--t]){
            rd[tt]--;
            if(rd[tt] == 0) cnt++;
        }
        std::cout<<cnt<<endl;
    }
}

signed main() {
    IOS;
    i32 T = 1;
    while (T--) nhir();
    return 0;
}