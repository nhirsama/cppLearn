//模板
#include <bits/stdc++.h>
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef std::pair<i32, i32> pii;
constexpr int N = 1e5 + 10;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()

struct Polynomial {
    constexpr static double PI = acos(-1);
    std::vector<std::complex<double> > c;

    Polynomial(std::vector<int> &a,i32 n) {
        c.resize(n);
        for (int i = 0; i < n; i++) {
            c[i] = std::complex<double>(a[i], 0);
        }
        fft(c, n, 1);
    }

    void change(std::vector<std::complex<double> > &a, int n) {
        for (int i = 1, j = n / 2; i < n - 1; i++) {
            if (i < j) std::swap(a[i], a[j]);
            int k = n / 2;
            while (j >= k) {
                j -= k;
                k /= 2;
            }
            if (j < k) j += k;
        }
    }

    void fft(std::vector<std::complex<double> > &a, int n, int opt) {
        change(a, n);
        for (int h = 2; h <= n; h *= 2) {
            std::complex<double> wn(cos(2 * PI / h), sin(opt * 2 * PI / h));
            for (int j = 0; j < n; j += h) {
                std::complex<double> w(1, 0);
                for (int k = j; k < j + h / 2; k++) {
                    std::complex<double> u = a[k];
                    std::complex<double> t = w * a[k + h / 2];
                    a[k] = u + t;
                    a[k + h / 2] = u - t;
                    w = w * wn;
                }
            }
        }
        if (opt == -1) {
            for (int i = 0; i < n; i++) {
                a[i].real /= n;
                a[i].imag /= n;
            }
        }
    }
};

void nhir() {
    i64 n, m;
    std::cin >> n >> m;
    std::vector<i32> a(n), b(m);
    for (auto &_: a)std::cin >> _;
    for (auto &_: b)std::cin >> _;
    Polynomial afft(a,n+m), bfft(b,n+m);
    afft


}

signed main() {
    IOS;
    i32 T = 1;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
        std::cin >> T;
    }

    while (T--) nhir();
    return 0;
}
