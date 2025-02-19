#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template <typename type>
class segment_tree {
public:
    struct tree {
        int l, r;
        type val;
    };

    vector<tree> tree;
    //根据题意修改线段树内存储的value

    explicit segment_tree(const int &n,const type &val = 0) {
        tree.resize(n << 2);
        build(1,n,1,val);
    }

    explicit segment_tree(const int &n,const vector<type> &vi) {
        tree.resize(n << 2);
        build(1,n,1,vi);
    }
    //若修改getval函数请注意修改query函数ans的初始值。
    static type getval(const type &a, const type &b) {
        return max(a, b);
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
        build(l, m, p << 1);
        build(m + 1, r, p << 1 | 1);
        pushup(p);
    }

    void build(const int &l, const int &r, const int &p, const vector<type> &vi) {
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
    type query(const int &l, const int &r, const int &p) {
        if (tree[p].l >= l && tree[p].r <= r) return tree[p].val;
        int m = tree[p].l + tree[p].r >> 1;
        type ans = 0;
        if (l <= m) ans = getval(ans, query(l, m, p << 1));
        if (r >= m) ans = getval(ans, query(l, m, p << 1 | 1));
        return ans;
    }

    void update(const int &p, const int &x, const type &v) {
        if (tree[p].l == x && tree[p].r == x) {
            tree[p].val = v;
        } else {
            const int mid = tree[p].l + tree[p].r >> 1;
            if (x <= mid) update(p << 1, x, v);
            else update(p << 1 | 1, x, v);
        }
        pushup(p);
    }
};

int main() {
    segment_tree<int> tree(5);

    return 0;
}
