//P1966 [NOIP 2013 提高组] 火柴排队
#include <bits/stdc++.h>
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef std::pair<i32, i32> pii;
constexpr int N = 1e5 + 10;
constexpr int mod = 1e8 - 3;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all(x) (x).begin(), (x).end()

template<class T>
class TreeArray {
public:
    std::vector<T> tree;
    int size;

    TreeArray(T n) {
        size = n;
        tree = std::vector<T>(n + 1, 0);
    }

    static T lowbit(T x) {
        return x & -x;
    }

    T getsum(T x) const {
        T sum = 0;
        while (x) {
            sum += tree[x];
            x -= lowbit(x);
        }
        return sum;
    }

    void update(T x, T k) {
        for (T i = x; i <= size; i += lowbit(i)) {
            tree[i] += k;
        }
    }
};

void nhir() {
    i32 n;
    std::cin >> n;
    std::vector<i32> a(n + 1), b(n + 1);
    std::vector<pii> c(n + 1), d(n + 1);
    for (i32 i = 1; i <= n; i++) {
        std::cin >> a[i];
        c[i] = {a[i], i};
    }
    std::sort(1 + all(c));
    for (i32 i = 1; i <= n; i++) {
        std::cin >> b[i];
        d[i] = {b[i], i};
    }
    std::sort(1 + all(d));
    for (i32 i = 1; i <= n; i++) {
        b[d[i].second] = c[i].second;
    }
    TreeArray<i32> ta(n + 1);
    i64 ans = 0;
    for (i32 i = n; i; i--) {
        ans += ta.getsum(b[i] - 1);
        ta.update(b[i], 1);
    }
    std::cout << ans % mod << endl;
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
