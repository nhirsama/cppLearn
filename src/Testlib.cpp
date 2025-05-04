#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
using __i_know_i_need_int = int;
constexpr __i_know_i_need_int mod = 1e9 + 7;
#define int __i_cannot_use_int
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
using pii = std::pair<__i_know_i_need_int, __i_know_i_need_int>;

void nhir() {
    i32 n;
    std::cin>>n;
    i32 au = n*10/100+(n*10%100!=0);
    i32 ag = n*30/100+(n*30%100!=0);
    i32 cu = n*60/100+(n*60%100!=0);
    //std::cout<<std::format("{} {} {}!", au, ag, cu);
    std::cout<<(std::string)std::format("金牌线:{},银牌线:{},铜牌线:{}",au,ag,cu);
}

signed main() {
    IOS;
    __i_know_i_need_int T = 1;
    while (T--) nhir();
    return 0;
}
