//  B. Sasha and the Apartment Purchase
#include <bits/stdc++.h>

using i64 = long long int;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void nhir() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for(auto &i:a) std::cin>>i;
    std::sort(all(a));
    int m = n - k;
    int p = (m + 1) / 2;
    std::cout << 0ll+a[n - p] - a[p - 1] + 1 << endl;
}

signed main() {
    IOS;
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}