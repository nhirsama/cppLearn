#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    int nk = N * K;
    vector<int> degree(nk + 1, 0); // 顶点编号从1到NK

    for (int i = 0; i < nk - 1; ++i) {
        int u, v;
        cin >> u >> v;
        degree[u]++;
        degree[v]++;
    }

    if (K == 1) {
        cout << "Yes" << endl;
        return 0;
    }

    bool is_chain = true;
    int leaf_count = 0;
    for (int i = 1; i <= nk; ++i) {
        if (degree[i] > 2) {
            is_chain = false;
        }
        if (degree[i] == 1) {
            leaf_count++;
        }
    }

    if (leaf_count != 2) {
        is_chain = false;
    }

    cout << (is_chain ? "Yes" : "No") << endl;

    return 0;
}