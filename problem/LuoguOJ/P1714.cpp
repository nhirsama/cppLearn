//P1714 切蛋糕
#include <bits/stdc++.h>
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef std::pair<i32, i32> pii;
constexpr int N = 1e5 + 10;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all1(x) (x).begin() + 1, (x).end()

template<typename T>
class SparseTable {
    using VT = std::vector<T>;
    using VVT = std::vector<VT>;
    using func_type = std::function<T(const T &, const T &)>;

    VVT ST;

    static T default_func(const T &t1, const T &t2) { return std::max(t1, t2); }

    func_type op;

public:
    SparseTable(const std::vector<T> &v, func_type _func = default_func) {
        op = _func;
        int len = v.size(), l1 = ceil(log2(len)) + 1;
        ST.assign(len, VT(l1, 0));
        for (int i = 0; i < len; ++i) {
            ST[i][0] = v[i];
        }
        for (int j = 1; j < l1; ++j) {
            int pj = (1 << (j - 1));
            for (int i = 0; i + pj < len; ++i) {
                ST[i][j] = op(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    i32 log(i32 lt) {
        i32 res = 0;
        while ((lt >> (res + 1))) { res++; }
        return res;
    }

    T query(int l, int r) {
        int lt = r - l + 1;
        int q = floor(log(lt));
        return op(ST[l][q], ST[r - (1 << q) + 1][q]);
    }
};

void nhir() {
    i32 n, m;
    std::cin >> n >> m;
    std::vector<i64> arr(n + 1);
    for (i32 i = 1; i <= n; i++) {
        std::cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    SparseTable<i64> st(arr);
    i64 max = 0;
    for (i32 i = 1; i <= n; i++) {
        max = std::max(st.query(i, std::min(i + m - 1, n)) - arr[i - 1], max);
    }
    std::cout << max << endl;
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
