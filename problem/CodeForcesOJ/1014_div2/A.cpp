//A
#include <bits/stdc++.h>
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef std::pair<i32, i32> pii;
constexpr int N = 1e5 + 10;
constexpr int mod = 1e9+7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void nhir() {
    i32 n;
    std::cin>>n;
    std::vector<i32> v(n);
    i32 ans = 0;
    for(auto &i:v) std::cin>>i;
    sort(all(v));

    std::cout<<v[n-1]-v[0]<<endl;
}

signed main() {
    IOS;
    i32 T = 1;
    std::cin>>T;
    while (T--) nhir();
    return 0;
}
