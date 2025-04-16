#include <bits/stdc++.h>

using i64 = long long int;
using i32 = int;
using pii = std::pair<i32, i32>;
constexpr int N = 1e5 + 10;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
/**   取模运算类（Z）
 *    2022-06-12: https://codeforces.com/contest/1697/submission/160317720
**/
constexpr int P = mod;
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

void nhir() {
    i32 n, m;
    std::cin >> n >> m;
    std::vector<i32> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }
    int inv2 = power(2, mod - 2, mod);

    std::vector<Z> dp(1024), newdp(1024);
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int x = 0; x < 1024; x++) {
            int t = x ^ v[i];
            newdp[x] = dp[x] + inv2 * dp[t];
        }
        std::swap(dp, newdp);
        newdp = std::vector<Z>(1024);
    }
    Z ans = 1;
    for (int i = 0; i < n; i++) {
        ans *= 2;
    }
    ans *= dp[m];
    std::cout << ans << endl;
}

signed main() {
    IOS;
    i32 T = 1;
    std::cout<<(1^2^3)<<endl;
    while (T--) nhir();
    return 0;
}
