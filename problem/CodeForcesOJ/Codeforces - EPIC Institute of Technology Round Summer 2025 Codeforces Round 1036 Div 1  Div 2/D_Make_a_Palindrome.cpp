//  D. Make a Palindrome
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

template<typename T>
struct Fenwick {
    int n;
    std::vector<T> a;

    Fenwick(int n_ = 0) {
        init(n_);
    }

    void init(int n_) {
        n = n_;
        a.assign(n, T{});
    }

    void add(int x, const T &v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] = a[i - 1] + v;
        }
    }

    T sum(int x) {
        T ans{};
        for (int i = x; i > 0; i -= i & -i) {
            ans = ans + a[i - 1];
        }
        return ans;
    }

    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }

    int select(const T &k) {
        int x = 0;
        T cur{};
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && cur + a[x + i - 1] <= k) {
                x += i;
                cur = cur + a[x - 1];
            }
        }
        return x;
    }
};

void nhir() {
    i32 n, k;
    std::cin >> n >> k;
//    std::multiset<i32> mu;
    Fenwick<i32> tr(n + 1);
    std::vector<i32> v(n);
    for (auto &i: v) std::cin >> i, tr.add(i, 1);
//    for (i32 i = 0; i < n; i++) {
//        std::cout << tr.sum(v[i] + 1) << ' ';
//    }
//    std::cout << endl;
    for (i32 l = 0, r = n - 1; l <= r;) {
        if (v[l] == v[r]) l++, r--;
        else {
            if (v[l] > v[r]) {
                if (tr.sum(v[l] + 1) >= k) {
                    tr.add(v[l], -1);
                    l++;
                } else {
                    std::cout << "NO\n";
                    return;
                }
            } else {
                if (tr.sum(v[r] + 1) >= k) {
                    tr.add(v[r], -1);
                    r--;
                } else {
                    std::cout << "NO\n";
                    return;
                }
            }
        }
    }
    std::cout << "YES\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}