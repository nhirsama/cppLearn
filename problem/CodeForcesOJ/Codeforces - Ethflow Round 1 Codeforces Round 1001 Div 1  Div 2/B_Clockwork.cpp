//  B. Clockwork
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
    bool ok = true;
    for(i32 i = 1;i<=n;i++){
        i32 x;
        std::cin>>x;
        if(std::max(n-i,i-1)*2>=x)ok = false;
    }
    std::cout<< (ok ? "YES\n" : "NO\n");
}

signed main() {
    IOS;
    i32 T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}