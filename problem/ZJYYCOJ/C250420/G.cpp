//模板
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
    int n;
    std::cin>>n;
    std::vector<i64> cf1(n+1),cf2(n+1);
    for (int i = 1;i<=n;i++) {
        std::cin>>cf1[i];
        cf2[i] = cf1[i];
    }
    i64 zans = 0,fans = 0;
    for (int i = 2;i<=n;i++) {
        if (i&1) {
            if (cf1[i]>=cf1[i-1]) zans+=cf1[i]-cf1[i-1]+1,cf1[i] = cf1[i-1]-1;
            if (cf2[i]<=cf2[i-1]) fans+=cf2[i-1]-cf2[i]+1,cf2[i] = cf2[i-1]+1;
        }
        else {
            if (cf2[i]>=cf2[i-1]) fans+=cf2[i]-cf2[i-1]+1,cf2[i] = cf2[i-1]-1;
            if (cf1[i]<=cf1[i-1]) zans+=cf1[i-1]-cf1[i]+1,cf1[i] = cf1[i-1]+1;
        }
    }
    // for (int i = 2;i<n;i++) {
    //     if (i&1) {
    //         if (cf[i]<=0) zans+=std::abs(cf[i]);
    //         if (cf[i]>=0) fans+=std::abs(cf[i]);
    //     }
    //     else {
    //         if (cf[i]<=0) fans+=std::abs(cf[i]);
    //         if (cf[i]>=0) zans+=std::abs(cf[i]);
    //     }
    // }
    std::cout<<std::min(fans,zans)<<endl;
}

signed main() {
    IOS;
    i32 T = 1;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
    }
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
