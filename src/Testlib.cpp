#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> ccb;
    vector<int> d;

    DSU(int n) : ccb(n + 1), d(n + 1, 0) {
        for (int i = 1; i <= n; ++i)
            ccb[i] = i;
    }

    int find(int x) {
        if (ccb[x] != x) {
            int root = find(ccb[x]);
            d[x] ^= d[ccb[x]];
            ccb[x] = root;
        }
        return ccb[x];
    }

    bool unite(int x, int y, int z) {
        int rx = find(x);
        int ry = find(y);
        if (rx == ry) {
            return (d[x] ^ d[y]) == z;
        }
        ccb[ry] = rx;
        d[ry] = d[x] ^ d[y] ^ z;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    DSU dsu(n);

    bool flag = true;
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        if (!dsu.unite(x, y, z)) {
            flag = false;
        }
    }

    if (!flag) {
        cout << -1 << '\n';
        return 0;
    }

    map<int, vector<int>> brr;
    for (int i = 1; i <= n; ++i) {
        int root = dsu.find(i);
        brr[root].push_back(i);
    }

    vector<int> arr(n + 1);
    for (auto &[root, nodes] : brr) {
        vector<int> bits(31, 0);
        for (int i : nodes) {
            int num = dsu.d[i];
            for (int k = 0; k < 31; ++k) {
                if (num & (1 << k))
                    bits[k]++;
            }
        }
        int n = nodes.size();
        int a = 0;
        for (int k = 0; k < 31; ++k) {
            if (bits[k] > n - bits[k])
                a |= (1 << k);
        }
        for (int i : nodes) {
            arr[i] = a ^ dsu.d[i];
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << arr[i] << " \n"[i == n];
    }

    return 0;
}