//  Stack
//  下午1:47
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"NowCoder"};
constexpr int P = 998244353;
using i64 = long long;

// assume -P <= x < 2P
int norm(int x) {
    if (x < 0) {
        x += P;
    }
    if (x >= P) {
        x -= P;
    }
    return x;
}

template<class T>
T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

struct Z {
    int x;

    Z(int x = 0) : x(norm(x)) {}

    Z(i64 x) : x(norm(x % P)) {}

    int val() const {
        return x;
    }

    Z operator-() const {
        return Z(norm(P - x));
    }

    Z inv() const {
        assert(x != 0);
        return power(*this, P - 2);
    }

    Z &operator*=(const Z &rhs) {
        x = i64(x) * rhs.x % P;
        return *this;
    }

    Z &operator+=(const Z &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }

    Z &operator-=(const Z &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }

    Z &operator/=(const Z &rhs) {
        return *this *= rhs.inv();
    }

    friend Z operator*(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res *= rhs;
        return res;
    }

    friend Z operator+(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res += rhs;
        return res;
    }

    friend Z operator-(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res -= rhs;
        return res;
    }

    friend Z operator/(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res /= rhs;
        return res;
    }

    friend std::istream &operator>>(std::istream &is, Z &a) {
        i64 v;
        is >> v;
        a = Z(v);
        return is;
    }

    friend std::ostream &operator<<(std::ostream &os, const Z &a) {
        return os << a.val();
    }
};

struct Comb {
    int n;
    std::vector<Z> _fac;
    std::vector<Z> _invfac;
    std::vector<Z> _inv;

    Comb() : n{0}, _fac{1}, _invfac{1}, _inv{0} {}

    Comb(int n) : Comb() {
        init(n);
    }

    void init(int m) {
        if (m <= n) return;
        _fac.resize(m + 1);
        _invfac.resize(m + 1);
        _inv.resize(m + 1);

        for (int i = n + 1; i <= m; i++) {
            _fac[i] = _fac[i - 1] * i;
        }
        _invfac[m] = _fac[m].inv();
        for (int i = m; i > n; i--) {
            _invfac[i - 1] = _invfac[i] * i;
            _inv[i] = _invfac[i] * _fac[i - 1];
        }
        n = m;
    }

    Z fac(int m) {
        if (m > n) init(2 * m);
        return _fac[m];
    }

    Z invfac(int m) {
        if (m > n) init(2 * m);
        return _invfac[m];
    }

    Z inv(int m) {
        if (m > n) init(2 * m);
        return _inv[m];
    }

    Z binom(int n, int m) {
        if (n < m || m < 0) return 0;
        return fac(n) * invfac(m) * invfac(n - m);
    }
} comb(5e5 + 10);
//std::vector<Z> th(5e5 + 10);

void nhir() {

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
//    std::array<std::array<Z, int(5e5 + 10)>, 2> dp{};
//    dp[1][1] = 1;
    std::array<Z, int(5e5 + 10)> ans;
    std::vector<Z> jc(5e5 + 10), dp(5e5 + 10), dp2(5e5 + 10), dp3(5e5 + 10);
    jc[0] = 1;

    for (int i = 1; i <= 5e5; i++) {
        jc[i] = jc[i - 1] * i;
        dp[i] = dp[i - 1] * i + jc[i - 1];
        dp2[i] = dp2[i - 1] * i + dp[i - 1] * 2 + jc[i - 1];
        dp3[i] = dp3[i - 1] * i + (dp2[i - 1] + dp[i - 1]) * 3 + jc[i - 1];
//        dp3[i] = power(dp[i - 1] * i, 3) + power(jc[i - 1], 3) + 3 * jc[i - 1] * power(dp[i - 1] * i, 2) +
//                 3 * jc[i - 1] * jc[i - 1] * dp[i - 1] * 2;
    }
//    ans[1] = 1;
//    for (int i = 2; i <= 5e5; i++) {
//        for (int j = 1; j <= i; j++)dp[i & 1][j] = dp[i ^ 1][j] * j + dp[i ^ 1][j - 1];
//        for (int j = 1; j <= i; j++) {
//            ans[j] = dp[i & 1][j] * power(Z(j), 3);
//        }
//    }
//    for (int i = 1; i <= 5e5; i++) {
//        th[i] = Z(1) / i;
//    }
//    for (int i = 1; i < 5; i++) std::cout << th[i] << ' ';
//    if (OJ_NAME != "AtCoder")
    std::cin >> T;
//    while (T--) nhir();
    while (T--) {
        int t;
        std::cin >> t;
        std::cout << dp3[t] << endl;
    }
    return 0;
}