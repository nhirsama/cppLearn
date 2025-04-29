//E
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
    std::string s;
    std::cin >> s;
    std::vector<int> dp(n + 2), nex(k, -1);
    dp[n] = 1;
    for (int i = n - 1; ~i; i--) {
        nex[s[i] - 'a'] = i;
        int mn = 0x3f3f3f3f;
        bool flag = false;
        for (int c = 0; c < k; c++) {
            if (nex[c] < 0) {
                dp[i] = 1;
                flag = true;
                break;
            }
            mn = std::min(mn, dp[nex[c] + 1] + 1);
        }
        if (!flag) dp[i] = mn;
    }
    std::vector<std::vector<int> > l(k);
    for (int i = 0; i < n; i++)
        l[s[i] - 'a'].push_back(i);
    int q;
    std::cin >> q;
    while (q--) {
        std::string t;
        std::cin >> t;
        int p = -1;
        for (char ch: t) {
            auto &v = l[ch - 'a'];
            auto it = upper_bound(v.begin(), v.end(), p);
            if (it == v.end()) {
                std::cout << 0 << endl;
                goto end;
            }
            p = *it;
        }
        std::cout << dp[p + 1] << endl;
        end:
    }
}

signed main() {
    IOS;
    i32 T = 1;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
    }
    while (T--) nhir();
    return 0;
}
