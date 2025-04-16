//  F. Trulimero Trulicina
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
    i32 n,m,k;
    std::cin>>n>>m>>k;
//    std::vector ans(n+1,std::vector<i32>(m+1));
//    i32 odd = 0,even = 1;
//    for(int i = 1;i<=n;i++){
//        for(int j = 1;j<=m;j++){
//            if((std::abs(i-j)&1) == 0){
//                ans[i][j] = (even%k)+1;
//                even+=2;
//            }
//            else {
//                ans[i][j] = (odd%k)+1;
//                odd+=2;
//            }
//        }
//    }
    bool t = (m%k == 0);
    i32 p = 0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            std::cout<<p%k+1<< ' ';
            p++;
        }
        p+=t;
        std::cout<<endl;
    }
}

signed main() {
    IOS;
    i32 T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}