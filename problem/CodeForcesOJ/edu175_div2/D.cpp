//D
#include <bits/stdc++.h>
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef std::pair<i32, i32> pii;
constexpr int N = 1e5 + 10;
constexpr int mod = 998244353;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all(x) (x).begin(), (x).end()

template<class T>
constexpr T mypow(T n, i64 k) {
    T r = 1;
    for (; k; k /= 2, n *= n) {
        if (k % 2) {
            r *= n;
        }
    }
    return r;
}

template<class T>
constexpr T power(int n) {
    return mypow(T(2), n);
}

template<const int &MOD>
struct Zmod {
    int x;

    Zmod(signed x = 0) : x(norm(x % MOD)) {
    }

    Zmod(i64 x) : x(norm(x % MOD)) {
    }

    constexpr int norm(int x) const noexcept {
        if (x < 0) [[unlikely]] {
            x += MOD;
        }
        if (x >= MOD) [[unlikely]] {
            x -= MOD;
        }
        return x;
    }

    explicit operator int() const {
        return x;
    }

    constexpr int val() const {
        return x;
    }

    constexpr Zmod operator-() const {
        Zmod val = norm(MOD - x);
        return val;
    }

    constexpr Zmod inv() const {
        assert(x != 0);
        return mypow(*this, MOD - 2);
    }

    friend constexpr auto &operator>>(std::istream &in, Zmod &j) {
        int v;
        in >> v;
        j = Zmod(v);
        return in;
    }

    friend constexpr auto &operator<<(std::ostream &o, const Zmod &j) {
        return o << j.val();
    }

    constexpr Zmod &operator++() {
        x = norm(x + 1);
        return *this;
    }

    constexpr Zmod &operator--() {
        x = norm(x - 1);
        return *this;
    }

    constexpr Zmod operator++(signed) {
        Zmod res = *this;
        ++*this;
        return res;
    }

    constexpr Zmod operator--(signed) {
        Zmod res = *this;
        --*this;
        return res;
    }

    constexpr Zmod &operator+=(const Zmod &i) {
        x = norm(x + i.x);
        return *this;
    }

    constexpr Zmod &operator-=(const Zmod &i) {
        x = norm(x - i.x);
        return *this;
    }

    constexpr Zmod &operator*=(const Zmod &i) {
        x = i64(x) * i.x % MOD;
        return *this;
    }

    constexpr Zmod &operator/=(const Zmod &i) {
        return *this *= i.inv();
    }

    constexpr Zmod &operator%=(const int &i) {
        return x %= i, *this;
    }

    friend constexpr Zmod operator+(const Zmod i, const Zmod j) {
        return Zmod(i) += j;
    }

    friend constexpr Zmod operator-(const Zmod i, const Zmod j) {
        return Zmod(i) -= j;
    }

    friend constexpr Zmod operator*(const Zmod i, const Zmod j) {
        return Zmod(i) *= j;
    }

    friend constexpr Zmod operator/(const Zmod i, const Zmod j) {
        return Zmod(i) /= j;
    }

    friend constexpr Zmod operator%(const Zmod i, const int j) {
        return Zmod(i) %= j;
    }

    friend constexpr bool operator==(const Zmod i, const Zmod j) {
        return i.val() == j.val();
    }

    friend constexpr bool operator!=(const Zmod i, const Zmod j) {
        return i.val() != j.val();
    }

    friend constexpr bool operator<(const Zmod i, const Zmod j) {
        return i.val() < j.val();
    }

    friend constexpr bool operator>(const Zmod i, const Zmod j) {
        return i.val() > j.val();
    }
};

void nhir() {
    i32 n;
    std::cin >> n;
    std::vector<i32> f(n + 1), cnt(n + 1);
    for (i32 i = 2; i <= n; i++) {
        std::cin >> f[i];
        cnt[i] = cnt[f[i]] + 1;
    }
    using Z = Zmod<mod>;

    std::vector<Z> dp(n + 1);
    std::vector<std::vector<int> > g(n + 1);
    for (int i = 1; i <= n; i++) {
        g[cnt[i]].push_back(i);
    }
    Z ans = 1;
    dp[0] = 1;
    Z sum = 1;
    for (int i = 1; i < n; i++) {
        Z nsum = 0;
        for (auto x: g[i]) {
            dp[x] = sum;
            if (i > 1) {
                dp[x] -= dp[f[x]];
            }
            nsum += dp[x];
        }
        sum = nsum;
        ans += sum;
    }
    std::cout << ans << "\n";
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
