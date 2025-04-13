//  P12132 [蓝桥杯 2025 省 B] 可分解的正整数
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
    std::vector<i32> num(n);
    for(auto &i:num) std::cin>>i;
    i32 cnt =0;
    for(auto i:num){
        if(i != 1) cnt++;
    }
    std::cout<<cnt<<endl;
}

signed main() {
    IOS;
    i32 T = 1;
    while (T--) nhir();
    return 0;
}