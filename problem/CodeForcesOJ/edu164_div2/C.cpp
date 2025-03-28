//C
#include <bits/stdc++.h>
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef std::pair<i32, i32> pii;
constexpr int N = 1e5 + 10;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void nhir() {
    std::string x,y;
    std::cin>>x>>y;
    bool flag = false;
    if (x<y) std::swap(x,y);
    for (i32 i = 0;i<x.size();i++) {
        if (x[i]>y[i] && !flag) {
            flag = true;
        }
        else if (x[i]>y[i]) std::swap(x[i],y[i]);
    }
    std::cout<<x<<'\n'<<y<<endl;
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
