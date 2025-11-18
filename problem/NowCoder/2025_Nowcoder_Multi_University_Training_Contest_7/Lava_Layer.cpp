//  Lava Layer
//  下午2:50
#include <bits/stdc++.h>

using i64 = long long int;
constexpr int MOD = 998244353;

int power(int a, i64 b, int p) {
    int res = 1;
    for (; b; b /= 2, a = 1LL * a * a % p) {
        if (b % 2) {
            res = 1LL * res * a % p;
        }
    }
    return res;
}

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

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 998244353;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"NowCoder"};
using Z = int64;
auto op = std::vector<std::function<Z(Z, Z)>>{
        [](Z a, Z b) { return a + b; },
        [](Z a, Z b) { return a * b; },
        [](Z a, Z b) { return Z(a & b); },
        [](Z a, Z b) { return Z(a | b); },
        [](Z a, Z b) { return Z(a ^ b); }
};


void nhir() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> num(k);
    Z ans = 0;
    for (int &i: num)std::cin >> i, ans += i;
    ans *= power(k, mod - 1, mod);
    for (int i = 1; i < n; i++) {
        Z t = 0;
        for (int nuu: num) {
            for (auto opp: op) {
                t += opp(ans, nuu);
            }
        }
        ans *= power(5, mod - 1, mod);
    }
    std::cout << ans << endl;

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    if (OJ_NAME != "AtCoder")
        std::cin >> T;
    while (T--) nhir();
    return 0;
}