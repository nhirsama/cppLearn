//  B. Move Back at a Cost
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
    std::vector<i32> v(n);
    for(auto &i:v) std::cin>>i;
    bool add = false;
    i32 min = v[n-1];
    std::priority_queue<pii> p;
    for(i32 i = n-1;~i;i--){
        if(v[i]<min) {
            min = v[i];
        }
        if(v[i]==min){
            p.push({v[i],i});
        }
        else {
            v[i]++;
            while(!p.empty() && v[i]<p.top().first){
                v[p.top().second]++;
                p.pop();
            }
        }
    }
    v[n-1]+=add;
    std::sort(all(v));
    for(auto i:v) std::cout<<i<< ' ';
    std::cout<<endl;
}

signed main() {
    IOS;
    i32 T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}