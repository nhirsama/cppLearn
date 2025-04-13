//  P12133 [蓝桥杯 2025 省 B] 产值调整
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = int;
using pii = std::pair<i32, i32>;
constexpr int N = 1e5 + 10;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
struct node{
    i32 a,b,c;
    node get(){
        return {(b+c)>>1,(a+c)>>1,(b+a)>>1};
    }
};
void nhir() {
    node a;
    i32 k;
    std::cin>>a.a>>a.b>>a.c>>k;
    for(i32 i = 1;i<=k;i++){
        a = a.get();
        if(a.a == a.b && a.b == a.c) break;
    }
    std::cout<<a.a<< ' '<<a.b<< ' '<<a.c<<endl;
}

signed main() {
    IOS;
    i32 T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}