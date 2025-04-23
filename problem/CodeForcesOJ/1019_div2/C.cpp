//C
#include <bits/stdc++.h>
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef std::pair<i32, i32> pii;
constexpr int N = 1e5 + 10;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void nhir() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> v(n + 1), pre(n + 1),suf(n+1);
    for (int i = 1; i <= n; i++) {
        std::cin >> v[i];
        v[i] = v[i] > k ? 1 : -1;
        pre[i] = pre[i - 1] + v[i];
    }
    suf[n] = v[n];
    for(int i = n-1;i;i--){
        suf[i] = suf[i+1]+v[i];
    }
    
//    if (std::count(pre.begin() + 1, pre.end()-1, 0) > 1) {
//        std::cout << "YES\n";
//        return;
//    }
//
//    int low = 0;
//    for (int l = 1; l < n - 1; l++) {
//        if (pre[l] <= 0 && pre[n] - pre[l] <= 0) {
//            low = l;
//        }
//    }
//    if (!low) {
//        std::cout << "NO\n";
//        return;
//    } else {
//        for (int r = low + 1; r < n; r++) {
//            if (pre[r] - pre[low] <= 0 || pre[n] - pre[r] <= 0) {
//                std::cout << "YES\n";
//                return;
//            }
//        }
//    }
//    std::cout << "YES\n";
//    return;
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
