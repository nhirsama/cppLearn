//  E - Temperature Fluctuation Range
//  20:37
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"AtCoder"};


template<typename type>
class max_segment_tree {
public:
    struct tree {
        int l, r;
        type val;
    };

    type initVal = -inf_i64;
    std::vector<tree> tree;
    //根据题意修改线段树内存储的value

    explicit max_segment_tree(const int &n, const type &val = 0) {
        tree.resize(n << 2);
        build(1, n, 1, val);
        initVal = val;
    }

    explicit max_segment_tree(const int &n, const std::vector<type> &vi) {
        tree.resize(n << 2);
        build(1, n, 1, vi);
    }

    //若修改getval函数请注意修改query函数ans的初始值。
    static type getval(const type &a, const type &b) {
        return std::max(a, b);
    }

    void pushup(const int &p) {
        tree[p].val = getval(tree[p << 1].val, tree[p << 1 | 1].val);
    }

    void build(const int &l, const int &r, const int &p, const type &val = 0) {
        tree[p].l = l;
        tree[p].r = r;
        if (l == r) {
            tree[p].val = val; //使用传入的初始值初始化，缺省则初始化为0
            return;
        }
        const int m = (l + r) >> 1;
        build(l, m, p << 1, val);
        build(m + 1, r, p << 1 | 1, val);
        pushup(p);
    }

    void build(const int &l, const int &r, const int &p, const std::vector<type> &vi) {
        tree[p].l = l;
        tree[p].r = r;
        if (l == r) {
            tree[p].val = vi[l]; // 使用实际数据初始化
            return;
        }
        const int mid = (l + r) >> 1;
        build(l, mid, p << 1, vi);
        build(mid + 1, r, p << 1 | 1, vi);
        pushup(p);
    }

    //若修改getval函数请注意修改query函数ans的初始值。
    type query(const int &l, const int &r, const int &p = 1) {
        if (tree[p].l >= l && tree[p].r <= r) return tree[p].val;
        int m = (tree[p].l + tree[p].r) >> 1;
        type ans = initVal;
        if (l <= m) ans = getval(ans, query(l, r, p << 1));
        if (r > m) ans = getval(ans, query(l, r, p << 1 | 1));
        return ans;
    }

    void update(const int &x, const type &v, const int &p = 1) {
        if (tree[p].l == x && tree[p].r == x) {
            tree[p].val = v;
        } else {
            const int mid = (tree[p].l + tree[p].r) >> 1;
            if (x <= mid) update(x, v, p << 1);
            else update(x, v, p << 1 | 1);
            pushup(p);
        }
    }
};


template<typename type>
class min_segment_tree {
public:
    struct tree {
        int l, r;
        type val;
    };

    type initVal = inf_i64;
    std::vector<tree> tree;
    //根据题意修改线段树内存储的value

    explicit min_segment_tree(const int &n, const type &val = 0) {
        tree.resize(n << 2);
        build(1, n, 1, val);
        initVal = val;
    }

    explicit min_segment_tree(const int &n, const std::vector<type> &vi) {
        tree.resize(n << 2);
        build(1, n, 1, vi);
    }

    //若修改getval函数请注意修改query函数ans的初始值。
    static type getval(const type &a, const type &b) {
        return std::min(a, b);
    }

    void pushup(const int &p) {
        tree[p].val = getval(tree[p << 1].val, tree[p << 1 | 1].val);
    }

    void build(const int &l, const int &r, const int &p, const type &val = 0) {
        tree[p].l = l;
        tree[p].r = r;
        if (l == r) {
            tree[p].val = val; //使用传入的初始值初始化，缺省则初始化为0
            return;
        }
        const int m = (l + r) >> 1;
        build(l, m, p << 1, val);
        build(m + 1, r, p << 1 | 1, val);
        pushup(p);
    }

    void build(const int &l, const int &r, const int &p, const std::vector<type> &vi) {
        tree[p].l = l;
        tree[p].r = r;
        if (l == r) {
            tree[p].val = vi[l]; // 使用实际数据初始化
            return;
        }
        const int mid = (l + r) >> 1;
        build(l, mid, p << 1, vi);
        build(mid + 1, r, p << 1 | 1, vi);
        pushup(p);
    }

    //若修改getval函数请注意修改query函数ans的初始值。
    type query(const int &l, const int &r, const int &p = 1) {
        if (tree[p].l >= l && tree[p].r <= r) return tree[p].val;
        int m = (tree[p].l + tree[p].r) >> 1;
        type ans = initVal;
        if (l <= m) ans = getval(ans, query(l, r, p << 1));
        if (r > m) ans = getval(ans, query(l, r, p << 1 | 1));
        return ans;
    }

    void update(const int &x, const type &v, const int &p = 1) {
        if (tree[p].l == x && tree[p].r == x) {
            tree[p].val = v;
        } else {
            const int mid = (tree[p].l + tree[p].r) >> 1;
            if (x <= mid) update(x, v, p << 1);
            else update(x, v, p << 1 | 1);
            pushup(p);
        }
    }
};


void nhir() {
    i32 n, k;
    std::cin >> n >> k;
    std::vector<i32> v(n + 1);
    // for (auto &i: v)std::cin >> i;
    for (int i = 1; i <= n; i++) std::cin >> v[i];
    // i32 l = 0, r = 2e9 + 1e5;

    auto mit = min_segment_tree<i32>(n, v);
    auto mat = max_segment_tree<i32>(n, v);
    // std::cout << mat.query(1, n) - mit.query(1, n) << endl;
    // while (l < r) {
    //     auto check = [&](i32 mid) {
    //         // 怎么最大值减最小值就行了，果然要好好看题啊
    //         // 原来限制了 k ，写完线段树怎么就忘了（
    //
    //         i32 ans = 0;
    //         for (int i = 1; i + k <= n; i++) {
    //             ans = std::max(ans, mat.query(i, i + k) - mit.query(i, i + k));
    //             // std::cout << mat.query(i, i + k) << mit.query(i, i + k) << std::endl;
    //         }
    //         return ans >= mid;
    //     };
    //     i32 mid = (l + r + 1) >> 1;
    //     if (check(mid)) {
    //         l = mid;
    //     } else {
    //         r = mid - 1;
    //     }
    // }
    i32 ans = 0;
    for (int i = 1; i + k - 1 <= n; i++) {
        ans = std::max(ans, mat.query(i, i + k - 1) - mit.query(i, i + k - 1));
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
