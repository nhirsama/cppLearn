//  C - K-bonacci
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = int;
using pii = std::pair<i32, i32>;
constexpr int N = 1e5 + 10;
constexpr int mod = 1e9;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void nhir() {
    i64 n,k;
    std::cin>>n>>k;
    std::vector<i64> arr(std::max(n+2,k+2));
    for(int i = 0;i<=k;i++) arr[i] = i;
    for(int i = k+1;i<n+2;i++) arr[i] = (arr[i-1]*2-arr[i-k-1]+mod)%mod;
    std::cout<<(arr[n+1]-arr[n]+mod)%mod;
}

signed main() {
    IOS;
    i32 T = 1;
    while (T--) nhir();
    return 0;
}