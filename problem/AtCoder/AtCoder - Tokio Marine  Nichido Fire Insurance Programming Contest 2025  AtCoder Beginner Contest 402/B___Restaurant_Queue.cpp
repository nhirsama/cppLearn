//  B - Restaurant Queue
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
    int q;
    std::cin>>q;
    std::queue<int> s;
    while(q--){
        int x,op;
        std::cin>>op;
        if(op == 1){
            std::cin>>x;
            s.push(x);
        }
        else {
            std::cout<<s.front()<<endl;
            s.pop();
        }
    }
}

signed main() {
    IOS;
    i32 T = 1;
    while (T--) nhir();
    return 0;
}