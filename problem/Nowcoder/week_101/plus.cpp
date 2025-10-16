//  幂中幂plus
#include <bits/stdc++.h>

using i64 = int64_t;
using i32 = int64_t;
//constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

template<typename V>
long long qpow(long long a, V b, long long M) {
    a = (a % M + M) % M;
    long long ans = ((M >= 2LL) ? 1LL : 0LL);
    while (b != V(0)) {
        if (b % V(2) != V(0)) {
            ans = ans * a % M;
        }
        a = a * a % M;
        b = b / V(2);
    }
    return ans;
}

template<class T>
constexpr T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

constexpr i64 mul(i64 a, i64 b, i64 p) {
    i64 res = a * b - i64(1.L * a * b / p) * p;
    res %= p;
    if (res < 0) {
        res += p;
    }
    return res;
}

template<i64 P>
struct MLong {
    i64 x;

    constexpr MLong() : x{} {}

    constexpr MLong(i64 x) : x{norm(x % getMod())} {}

    static i64 Mod;

    constexpr static i64 getMod() {
        if (P > 0) {
            return P;
        } else {
            return Mod;
        }
    }

    constexpr static void setMod(i64 Mod_) {
        Mod = Mod_;
    }

    constexpr i64 norm(i64 x) const {
        if (x < 0) {
            x += getMod();
        }
        if (x >= getMod()) {
            x -= getMod();
        }
        return x;
    }

    constexpr i64 val() const {
        return x;
    }

    explicit constexpr operator i64() const {
        return x;
    }

    constexpr MLong operator-() const {
        MLong res;
        res.x = norm(getMod() - x);
        return res;
    }

    constexpr MLong inv() const {
        assert(x != 0);
        return power(*this, getMod() - 2);
    }

    constexpr MLong &operator*=(MLong rhs) &{
        x = mul(x, rhs.x, getMod());
        return *this;
    }

    constexpr MLong &operator+=(MLong rhs) &{
        x = norm(x + rhs.x);
        return *this;
    }

    constexpr MLong &operator-=(MLong rhs) &{
        x = norm(x - rhs.x);
        return *this;
    }

    constexpr MLong &operator/=(MLong rhs) &{
        return *this *= rhs.inv();
    }

    friend constexpr MLong operator*(MLong lhs, MLong rhs) {
        MLong res = lhs;
        res *= rhs;
        return res;
    }

    friend constexpr MLong operator+(MLong lhs, MLong rhs) {
        MLong res = lhs;
        res += rhs;
        return res;
    }

    friend constexpr MLong operator-(MLong lhs, MLong rhs) {
        MLong res = lhs;
        res -= rhs;
        return res;
    }

    friend constexpr MLong operator/(MLong lhs, MLong rhs) {
        MLong res = lhs;
        res /= rhs;
        return res;
    }

    friend constexpr std::istream &operator>>(std::istream &is, MLong &a) {
        i64 v;
        is >> v;
        a = MLong(v);
        return is;
    }

    friend constexpr std::ostream &operator<<(std::ostream &os, const MLong &a) {
        return os << a.val();
    }

    friend constexpr bool operator==(MLong lhs, MLong rhs) {
        return lhs.val() == rhs.val();
    }

    friend constexpr bool operator!=(MLong lhs, MLong rhs) {
        return lhs.val() != rhs.val();
    }
};

template<>
i64 MLong<0LL>::Mod = i64(1E18) + 9;

template<int P>
struct MInt {
    int x;

    constexpr MInt() : x{} {}

    constexpr MInt(i64 x) : x{norm(x % getMod())} {}

    static int Mod;

    constexpr static int getMod() {
        if (P > 0) {
            return P;
        } else {
            return Mod;
        }
    }

    constexpr static void setMod(int Mod_) {
        Mod = Mod_;
    }

    constexpr int norm(int x) const {
        if (x < 0) {
            x += getMod();
        }
        if (x >= getMod()) {
            x -= getMod();
        }
        return x;
    }

    constexpr int val() const {
        return x;
    }

    explicit constexpr operator int() const {
        return x;
    }

    constexpr MInt operator-() const {
        MInt res;
        res.x = norm(getMod() - x);
        return res;
    }

    constexpr MInt inv() const {
        assert(x != 0);
        return power(*this, getMod() - 2);
    }

    constexpr MInt &operator*=(MInt rhs) &{
        x = 1LL * x * rhs.x % getMod();
        return *this;
    }

    constexpr MInt &operator+=(MInt rhs) &{
        x = norm(x + rhs.x);
        return *this;
    }

    constexpr MInt &operator-=(MInt rhs) &{
        x = norm(x - rhs.x);
        return *this;
    }

    constexpr MInt &operator/=(MInt rhs) &{
        return *this *= rhs.inv();
    }

    friend constexpr MInt operator*(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res *= rhs;
        return res;
    }

    friend constexpr MInt operator+(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res += rhs;
        return res;
    }

    friend constexpr MInt operator-(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res -= rhs;
        return res;
    }

    friend constexpr MInt operator/(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res /= rhs;
        return res;
    }

    friend constexpr std::istream &operator>>(std::istream &is, MInt &a) {
        i64 v;
        is >> v;
        a = MInt(v);
        return is;
    }

    friend constexpr std::ostream &operator<<(std::ostream &os, const MInt &a) {
        return os << a.val();
    }

    friend constexpr bool operator==(MInt lhs, MInt rhs) {
        return lhs.val() == rhs.val();
    }

    friend constexpr bool operator!=(MInt lhs, MInt rhs) {
        return lhs.val() != rhs.val();
    }
};

template<>
int MInt<0>::Mod = 998244353;

template<int V, int P>
constexpr MInt<P> CInv = MInt<P>(V).inv();

constexpr int P = 1000000007;
using Z = MInt<0>;

void nhir() {
    i64 base, c0, mod;
    std::cin >> base >> c0 >> mod;

    Z::setMod(mod);
//    std::vector<bool> vis(P);
    std::map<i64, i64> m;
//    std::vector<i64> c(P);
//    c[0] = c0;
    i64 be, en;
    std::vector<Z> c;
    i32 now = c0;
    for (i64 i = 0;; i++, now = qpow(base, now, mod)) {
//        c[i] = power(base, c[i - 1]);
        if (now < mod && m.contains(now)) {
            be = m[now];
            en = i;
            break;
        }
        c.emplace_back(now);
        m[now] = i;
    }
    std::vector<Z> pre(c.size() + 1);
//    c[0] = 0;
    for (int i = 0; i < c.size(); ++i) {
        pre[i + 1] = pre[i] + c[i];
    }
    i64 len = en - be;
    int q;
    std::cin >> q;
    while (q--) {
        i64 k;
        std::cin >> k;
        if (k < be) {
            std::cout << pre[k + 1] - pre[1] << enld;
        } else {
            Z ans = 0;
            ans += pre[be] - pre[1];
            ans += (pre[en] - pre[be]) * ((k - be + 1) / len);
            ans += pre[(k - be + 1) % len + be] - pre[be];
            std::cout << ans << endl;
        }
    }
}
//void nhir() {
//    i32 base, c0, Mod;
//    std::cin >> base >> c0 >> Mod;
//    i32 q;
//    std::cin >> q;
//    std::map<i32, i32> m;
//    std::vector<i32> c(1e6 + 10);
//    c[0] = c0;
//    m[c[0]] = 0;
//    i32 be, en;
////    i32 f = true;
//    for (i32 i = 1; i <= 1e6; i++) {
//        i32 ci = power(base, c[i - 1], Mod) % Mod;
//        c[i] = ci;
//        if (m.find(ci) != m.end()) {
//            be = m[ci];
//            en = i;
////            f = false;
//            break;
//        }
////        c[i] = ci;
//        m[ci] = i;
////        m[ci] = i;
//    }
//    std::vector<i32> pre(1e6 + 10);
//    for (i32 i = 1; i <= 1e6; i++) pre[i] = (pre[i - 1] + c[i]) % Mod;
//    i32 len = en - be;
//    while (q--) {
//        i32 i;
//        std::cin >> i;
//        if (i < en) {
//            std::cout << pre[i] << endl;
//        } else {
//            i32 ans = pre[be - 1];
//            ans = (ans + (pre[en - 1] - pre[be - 1] + Mod) % Mod * ((i - be) / len % Mod) % Mod) % Mod;
//            ans = (ans + pre[be + (i - be) % len] - pre[be - 1] + Mod) % Mod;
//            std::cout << ans << enld;
////            i32 sum = (pre[en] - pre[be] + Mod) % Mod;
////            i32 ans = pre[be];
////            i -= be;
////            i64 cnt = i / len, rem = i % len;
////            ans = (ans + cnt % Mod * sum % Mod) % Mod;
////            ans = (ans + (pre[be + rem] - pre[be] + Mod) % Mod) % Mod;
////            std::cout << ans % Mod << endl;
////            i32 ans = 0;
////            ans += pre[be - 1];
////            i -= be;
////            ans = (ans + (pre[en] - pre[be - 1]) % Mod * ((i / len) % Mod) +
////                   (pre[be + i % len] - pre[be - 1]) % Mod) %
////                  Mod;
////            std::cout << ans % Mod << enld;
//        }
//    }
//}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
//    std::cin >> T;
    while (T--) nhir();
    return 0;
}