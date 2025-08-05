#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using i128 = __int128;

template<int mod>
struct Modint {
    unsigned int x;

    Modint() : x(0) {};

    Modint(unsigned int x) : x(x) {}

    static unsigned int down(unsigned int x) { return x >= mod ? x - mod : x; }

    friend istream &operator>>(istream &in, Modint &a) { return in >> a.x; }

    friend ostream &operator<<(ostream &out, Modint a) { return out << a.x; }

    friend Modint operator+(Modint a, Modint b) { return Modint(Modint::down(a.x + b.x)); }

    friend Modint operator-(Modint a, Modint b) { return Modint(Modint::down(a.x - b.x + mod)); }

    friend Modint operator*(Modint a, Modint b) { return 1ULL * a.x * b.x % mod; }

    friend Modint operator/(Modint a, Modint b) { return a * ~b; }

    friend Modint operator^(Modint a, long long b) {
        Modint ans = 1;
        for (; b; b >>= 1, a *= a) if (b & 1) ans *= a;
        return ans;
    }

    friend Modint operator~(Modint a) { return a ^ (mod - 2); }

    friend Modint operator-(Modint a) { return Modint(Modint::down(mod - a.x)); }

    friend Modint &operator+=(Modint &a, Modint b) { return a = a + b; }

    friend Modint &operator-=(Modint &a, Modint b) { return a = a - b; }

    friend Modint &operator*=(Modint &a, Modint b) { return a = a * b; }

    friend Modint &operator/=(Modint &a, Modint b) { return a = a / b; }

    friend Modint &operator^=(Modint &a, long long b) { return a = a ^ b; }

    friend Modint &operator++(Modint &a) { return a += 1; }

    friend Modint &operator--(Modint &a) { return a -= 1; }

    friend Modint operator++(Modint &a, int) {
        Modint x = a;
        a += 1;
        return x;
    }

    friend Modint operator--(Modint &a, int) {
        Modint x = a;
        a -= 1;
        return x;
    }

    friend bool operator==(Modint a, Modint b) { return a.x == b.x; }

    friend bool operator!=(Modint a, Modint b) { return a.x != b.x; }
};

constexpr int M = 998244353;
using Z = Modint<M>;
std::vector<int> minp, primes;

void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();

    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }

        for (auto p: primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
}

// Miller-Rabin
bool is_prime(i64 n) {
    if (n < 2) return false;
    for (i64 p: {2, 3, 5, 7, 11, 13, 17, 19, 23, 29}) {
        if (n == p) return true;
        if (n % p == 0) return false;
    }
    i64 d = n - 1, r = 0;
    while ((d & 1) == 0) d >>= 1, r++;
    for (i64 a: {2, 3, 5, 7, 11}) {
        i64 x = 1, base = a % n, exp = d;
        while (exp) {
            if (exp & 1) x = (__int128) x * base % n;
            base = (__int128) base * base % n;
            exp >>= 1;
        }
        if (x == 1 || x == n - 1) continue;
        bool ok = false;
        for (int i = 0; i < r - 1; i++) {
            x = (__int128) x * x % n;
            if (x == n - 1) {
                ok = true;
                break;
            }
        }
        if (!ok) return false;
    }
    return true;
}

// Pollard-Rho
i64 pollard(i64 n) {
    if (n % 2 == 0) return 2;
    mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
    while (1) {
        i64 x = rnd() % (n - 2) + 2;
        i64 y = x;
        i64 c = rnd() % (n - 1) + 1;
        i64 d = 1;
        while (d == 1) {
            x = (__int128(x) * x + c) % n;
            y = (__int128(y) * y + c) % n;
            y = (__int128(y) * y + c) % n;
            d = gcd(abs(x - y), n);
        }
        if (d != n) return d;
    }
}

unordered_map<i64, vector<pair<i64, int>>> fac;

unordered_map<i64, int> factor(i64 n) {
    unordered_map<i64, int> cnt;
    auto dfs = [&](auto &&dfs, i64 x) {
        if (x == 1) return;
        if (is_prime(x)) {
            cnt[x]++;
            return;
        }
        i64 f = pollard(x);
        dfs(dfs, f);
        dfs(dfs, x / f);
    };
    dfs(dfs, n);
    return cnt;
}

vector<pair<i64, int>> get_factor(i64 G) {
    auto it = fac.find(G);
    if (it != fac.end()) {
        return it->second;
    }
    std::unordered_map<i64, int> umm;
    for (int p: primes) {
        while (G % p == 0) {
            umm[p]++;
            G /= p;
        }
    }
    if (G > 1) {
        auto mp = factor(G);
        for (auto [p, cnt]: mp) {
            umm[p] += cnt;
        }
    }
//    auto mp = factor(G);
    vector<pair<i64, int>> v(umm.begin(), umm.end());
    return fac[G] = v;
}

int cntpow(i64 n, i64 p) {
    int cnt = 0;
    while (n % p == 0) {
        n /= p;
        cnt++;
    }
    return cnt;
}

void solve() {
    i64 a, b, c, d;
    cin >> a >> b >> c >> d;

    i64 G = gcd(a, c);

    Z ans = 1;
    auto f = get_factor(G);
    for (auto [p, _]: f) {
        int cnta = cntpow(a, p);
        int cntc = cntpow(c, p);
        ans *= Z(p % M) ^ (min(i128(b) * cnta, i128(d) * cntc) % (M - 1));
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve(1e6);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}