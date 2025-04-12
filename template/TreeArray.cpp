#include <bits/stdc++.h>
template<class T>
class TreeArray {
public:
    std::vector<T> tree;
    int size;
    TreeArray(T n) {
        size = n;
        tree = std::vector<T>(n+1,0);
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