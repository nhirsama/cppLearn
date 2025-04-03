//C
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
i32 find(std::vector<i64> &root,i32 n) {
    return root[n] == n ? n : root[n] = find(root,root[n]);
}
void nhir() {
    i64 n;
    std::cin >> n;
    std::vector<i64> a(n+1), c(n+1),root(n+1);
    for (i32 i = 1;i<=n;i++) std::cin >> a[i],root[i] = i;
    for(i32 i = 1; i <= n; i++) root[find(root,a[i])] = find(root,a[a[i]]);
    for (i32 i = 1; i <= n; i++) c[find(root,i)]++;
    i64 ans = 0;
    for (i32 i = 1; i <= n; i++) {
        i64 t = 0;
        std::cin >> t;
        ans+=c[find(root,t)];
        std::cout << ans <<  ' ';
        c[find(root,t)]=0;
    }
    std::cout << '\n';
}

signed main() {
    IOS;
    i32 T = 1;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
    }
    std::cin>>T;
    while (T--) nhir();
    return 0;
}
