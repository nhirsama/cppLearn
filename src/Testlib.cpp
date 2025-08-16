//  AVL tree
//  12:38
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"NowCoder"};
constexpr int maxh = 30;
std::vector<int> fib(maxh + 10);

void nhir() {
    int n;
    std::cin >> n;
    std::vector<int> t(2 * n + 2);
    for (int i = 1; i <= n; i++) {
        int l, r;
        std::cin >> l >> r;
        t[i * 2] = l;
        t[i * 2 + 1] = r;
    }
    std::vector<int> cnt(n + 1), th(n + 1);
    std::vector dp(n + 1, std::vector<int>(maxh, 0x3f3f3f3f));
    for (int i = 0; i < maxh; i++) {
        dp[0][i] = fib[i];
    }
    auto get = [&](int u, int h) {
        if (h < 0) return 0x3f3f3f3f;
        return std::min(dp[u][h], cnt[u] + fib[h]);
    };
    auto dfs = [&](auto &&self, int u) -> void {
        int ls = t[u * 2], rs = t[u * 2 + 1];
        if (ls) {
            self(self, ls);
        }
        if (rs) {
            self(self, rs);
        }
        cnt[u] = cnt[ls] + cnt[rs] + 1;
        th[u] = std::max(th[ls], th[rs]) + 1;
        // dp[u][0] = 0;
        for (int i = 1; i < maxh; i++) {
            dp[u][i] = std::min(dp[u][i], get(ls, i - 1) + get(rs, i - 1));
            dp[u][i] = std::min(dp[u][i], get(ls, i - 1) + get(rs, i - 2));
            dp[u][i] = std::min(dp[u][i], get(ls, i - 2) + get(rs, i - 1));
        }
    };
    dfs(dfs, 1);
    int ans = 0x3f3f3f3f;
    for (int i = 0; i < maxh; i++) {
        ans = std::min(ans, dp[1][i]);
    }
    std::cout << ans << endl;
    /*
    std::vector<int> dp(n + 1);
    std::vector<int> h(n + 1), cnt(n + 1);
    auto dfs = [&](auto &&self, int u)-> void {
        int ls = t[u * 2], rs = t[u * 2 + 1];
        if (ls) {
            self(self, ls);
        }
        if (rs) {
            self(self, rs);
        }
        if (std::abs(h[ls] - h[rs]) <= 1) {
            dp[u] = dp[ls] + dp[rs];
            h[u] = std::max(h[ls], h[rs]) + 1;
            cnt[u] = cnt[ls] + cnt[rs] + 1;
        } else {
            if (h[ls] > h[rs]) std::swap(ls, rs);
            int ll = h[ls], rr = h[rs];
            int ansh = ll;
            for (int i = ll; i < rr; i++) {
                if (std::max(fib[i] - cnt[ls], 0) + (rr == i + 1 ? 0 : std::max(cnt[rs] - fib[i + 1], 0)) <
                    std::max(fib[ansh] - cnt[ls], 0) + (rr == ansh + 1 ? 0 : std::max(cnt[rs] - fib[ansh + 1], 0))) {
                    ansh = i;
                }
            }
            h[u] = ansh + 2;
            if (ll != ansh) cnt[u] += fib[ansh];
            else cnt[u] += cnt[ls];
            if (rr != ansh) cnt[u] += fib[ansh + 1];
            else cnt[u] += cnt[rs];
            cnt[u]++;
            dp[u] = dp[ls] + dp[rs] + std::max(fib[ansh] - cnt[ls], 0) +
                    (rr == ansh + 1 ? 0 : std::max(cnt[rs] - fib[ansh + 1], 0));
        }
    };
    dfs(dfs, 1);
    std::cout << dp[1] << enld;
    */
}

struct s1 {
    int a;
    bool b;

    s1 operator+(const s1 c) const {
        return {this->a + c.a, static_cast<bool>((this->b) & c.b)};
    }
};

struct s2 {
    int a;
    bool b;

    s2 operator-(const s2 c) const {
        return {this->a - c.a, static_cast<bool>((this->b) ^ c.b)};
    }
};

signed main() {
    auto t = {10, true};
    s1 tt{10, false};
    auto a = std::move(tt);
    return 0;
}
