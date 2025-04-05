//D
#include <bits/stdc++.h>
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef std::pair<i32, i32> pii;
constexpr int N = 5e5 + 10;
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

using Z = Zmod<mod>;
i64 jc[N];

i64 pow(i64 a, i32 b) {
    // 复杂度是 log N
    i64 r = 1 % mod; /**! 这里的取模容易遗漏 */
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1) r = r * a % mod;
    }
    return r;
}

void init() {
    jc[0] = 1;
    for (i64 i = 1; i < N; i++) {
        jc[i] = jc[i - 1] * i % mod;
    }
}

void nhir() {
    std::vector<int> v(26);
    int sum = 0;
    for (auto &i: v) {
        std::cin >> i;
        sum += i;
    }
    std::vector<Z> dp(sum + 1);
    dp[0] = 1;
    for (i32 i: v) {
        if (!i) continue;
        for (i32 j = sum - i; ~j; j--) {
            dp[j + i] = dp[j + i] + dp[j];
        }
    }
    Z ans = 0;
    i32 odd = (sum + 1) / 2, even = sum / 2;
    ans = jc[even] * jc[odd] * dp[odd];
    for (i32 i: v) {
        ans *= pow(jc[i], mod - 2);
    }
    std::cout << ans << endl;
}

signed main() {
    IOS;
    i32 T = 1;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
    }
    std::cin >> T;
    init();
    while (T--) nhir();
    return 0;
}
