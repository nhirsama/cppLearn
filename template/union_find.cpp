//
// Created by Origami on 25-4-6.
//
#include <vector>
#include <iostream>
/**
 * @class UnionFind
 * @brief 实现带路径压缩和按秩合并优化的并查集数据结构
 *
 * 支持以下操作：
 * - 合并两个元素的集合（O(α(n))）
 * - 查询元素的根节点（O(α(n))）
 * - 直观的运算符语法进行集合操作
 *
 * @note 元素索引应为 [0, n-1] 范围内的整数
 */
struct UnionFind {
private:
    mutable std::vector<int> parent;
    std::vector<int> rank;

    struct ElementProxy {
        UnionFind &uf;
        int index;

        operator int() const { return uf.find(index); }

        void operator=(const ElementProxy &other) {
            uf.merge(index, other.index);
        }
    };

public:
    explicit UnionFind(int n) : parent(n), rank(n, 1) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int x) const {
        return parent[x] == x ? x : (parent[x] = find(parent[x]));
    }

    void merge(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return;

        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootX] = rootY;
            if (rank[rootX] == rank[rootY]) ++rank[rootY];
        }
    }

    ElementProxy operator[](int x) {
        return {*this, x};
    }

    // const 版本调用 const find
    int operator[](int x) const {
        return find(x);
    }
};

/*
int main() {
    UnionFind uf(5);

    // 合并操作
    uf[0] = uf[1]; // 合并0和1
    uf[2] = uf[3]; // 合并2和3
    uf[1] = uf[3]; // 合并{0,1}和{2,3}

    // 连通性判断
    std::cout << "0和3是否连通: " << (uf[0] == uf[3]) << "\n"; // 输出1
    std::cout << "1和4是否连通: " << (uf[1] != uf[4]) << "\n"; // 输出1
}
*/
