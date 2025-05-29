struct msg {
    i32 lazy;
    i32 sum;
};

template<typename T>
class segtree {
private:
    int n;
    std::vector<msg> segmsg;

    void merge(int node) {
        segmsg[node].sum = segmsg[2 * node + 1].sum + segmsg[2 * node + 2].sum;
    }

    void pushdown(int node, int len) {
        auto &[lazy, sum] = segmsg[node];
        sum += lazy * len;
        if (node * 2 + 1 < 4 * n) {
            segmsg[2 * node + 1].lazy += lazy;
            segmsg[2 * node + 2].lazy += lazy;
        }
        lazy = 0;
    }

    void build(int node, int l, int r, std::vector<T> &nums) {
        if (l == r) {
            segmsg[node] = {0, nums[l]};
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node + 1, l, mid, nums);
        build(2 * node + 2, mid + 1, r, nums);
        merge(node);
    }

    void add(int node, int l, int r, int ql, int qr, T val) {
        pushdown(node, r - l + 1);
        if (ql <= l && r <= qr) {
            segmsg[node].lazy += val;
            pushdown(node, r - l + 1);
            return;
        }
        if (r < ql || qr < l) return;
        int mid = (l + r) / 2;
        add(node * 2 + 1, l, mid, ql, qr, val);
        add(node * 2 + 2, mid + 1, r, ql, qr, val);
        merge(node);
    }

    T getsum(int node, int l, int r, int ql, int qr) {
        pushdown(node, r - l + 1);
        if (ql <= l && r <= qr) return segmsg[node].sum;
        if (r < ql || qr < l) return 0;
        int mid = (l + r) / 2;
        return getsum(2 * node + 1, l, mid, ql, qr) + getsum(2 * node + 2, mid + 1, r, ql, qr);
    }

public:
    segtree() = default;

    segtree(std::vector<T> &nums) {
        n = nums.size();
        segmsg.resize(4 * n);
        build(0, 0, n - 1, nums);
    }

    void build(std::vector<T> &nums) {
        n = nums.size();
        segmsg.resize(4 * n);
        build(0, 0, n - 1, nums);
    }

    void add(int l, int r, T val) {
        add(0, 0, n - 1, l, r, val);
    }

    T getsum(int l, int r) {
        return getsum(0, 0, n - 1, l, r);
    }
};