//  P12134 [蓝桥杯 2025 省 B] 画展布置
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
    i64 n,m;
    std::cin>>n>>m;
    std::vector<i64> v(n);
    for(auto &i:v) std::cin>>i;
    std::sort(all(v));
    i64 min = 0x3f3f3f3f3f3f3f3f;
    for(i32 i = 0;i+m-1<n;i++){
        min = std::min(min,v[i+m-1]*v[i+m-1]-v[i]*v[i]);
    }
    std::cout<<min<<endl;

}

signed main() {
    IOS;
    i32 T = 1;
    while (T--) nhir();
    return 0;
}