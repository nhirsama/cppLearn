//  A. Simple Permutation
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = int;
using pii = std::pair<i32, i32>;
constexpr int N = 1e5 + 10;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
bool isPrime(int x){
    if(x <= 1)
        return 0;
    for(int i = 2 ; i * i <= x ; ++i)
        if(x % i == 0)
            return 0;
    return 1;
}
void nhir() {
    i32 n;
    std::cin>>n;
    std::vector<i32> ans;
    i32 p;
    for(i32 i = n/3;i<=(2*n+2)/3;i++){
        if(isPrime(i)) {
            p = i;
            break;
        }
    }
    ans.push_back(p);
    for(i32 i = 1;i<=n;i++){
        if(p-i>0) ans.push_back(p-i);
        if(p+i<=n) ans.push_back(p+i);
    }
    for(i32 i = 0;i<n;i++){
        std::cout<<ans[i]<< ' ';
    }
    std::cout<<endl;
}

signed main() {
    IOS;
    i32 T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}