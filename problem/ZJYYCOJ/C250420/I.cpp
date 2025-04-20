//模板
#include <bits/stdc++.h>
using i64 = long long int;
using i32 = int;
using pii = std::pair<i32, i32>;
constexpr int N = 1e5 + 10;
constexpr int mod = 998244353;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#include <bits/stdc++.h>
using i64 = long long int;

int power(int a, i64 b, int p) {
    int res = 1;
    for (; b; b /= 2, a = 1LL * a * a % p) {
        if (b % 2) {
            res = 1LL * res * a % p;
        }
    }
    return res;
}
void nhir() {
    int n;
    std::cin>>n;
    std::vector g(n,std::vector<int> ());
    for (int i = 1;i<n;i++) {
        int u,v;
        std::cin>>u>>v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int cntt = 0;
    std::vector<int> cnt(n);
    auto dfs = [&](auto && self,int u,int f)->void {
        for (auto v:g[u]) {
            if (v  == f) continue;
            self(self,v,u);
            cnt[u]+=cnt[v];
            if (cnt[v]%2 == 0) {
                cntt++;
            }
        }
        cnt[u]++;
    };
    dfs(dfs,0,-1);
    if (cntt == 0) {
        std::cout<<0<<endl;
    }
    else {
        std::cout<<(0ll+power(2,cntt,mod)+mod-1)%mod<<endl;
    }
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
