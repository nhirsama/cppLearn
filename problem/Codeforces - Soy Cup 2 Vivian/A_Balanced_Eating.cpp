//  A. Balanced Eating
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
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

    Z(int x = 0) : x(norm(x)) {
    }

    Z(i64 x) : x(norm(x % P)) {
    }

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

int power(int a, i64 b, int p) {
    int res = 1;
    for (; b; b /= 2, a = 1LL * a * a % p) {
        if (b % 2) {
            res = 1LL * res * a % p;
        }
    }
    return res;
}

struct Comb {
    int n;
    std::vector<Z> _fac;
    std::vector<Z> _invfac;
    std::vector<Z> _inv;

    Comb() : n{0}, _fac{1}, _invfac{1}, _inv{0} {
    }

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
} comb;

void nhir() {
    i32 n;
    std::cin >> n;
    std::vector<i32> v(n);
    i32 cnt = 0;
    for (auto &i: v)std::cin >> i;
    for (auto i: v)if (i & 1) cnt++;
    if (cnt == 0) {
        std::cout << 1 << endl;
        return;
    }
    Z ans = comb.binom(cnt, cnt / 2);
    i32 fm = power(2, cnt - (cnt & 1), P);
    ans /= fm;
    std::cout << ans << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
