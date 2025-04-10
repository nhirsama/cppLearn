#include <bits/stdc++.h>
using i64 = long long int;
constexpr int MOD = 1e9 + 7;

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
