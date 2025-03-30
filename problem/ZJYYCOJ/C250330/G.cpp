//模板
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
    i32 h1,m1,s1,h2,m2,s2;
    std::scanf("%d:%d:%d",&h1,&m1,&s1);
    std::scanf("%d:%d:%d",&h2,&m2,&s2);
    i64 ans = 0;
    ans = (h2-h1)*3600;
    ans += (m2-m1)*60;
    ans += (s2-s1);
    std::cout << std::abs(ans) <<endl;
}

signed main() {
    i32 T = 1;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
        std::cin >> T;
    }

    while (T--) nhir();
    return 0;
}
