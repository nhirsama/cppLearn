#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> pre_gt(n, vector<int>(n, 0));
    vector<vector<int>> pre_lt(n, vector<int>(n, 0));
    for (int l = 0; l < n; l++) {
        int current_gt = 0, current_lt = 0;
        for (int r = l + 1; r < n; r++) {
            if (a[r] > a[l]) current_gt++;
            else if (a[r] < a[l]) current_lt++;
            pre_gt[l][r] = current_gt;
            pre_lt[l][r] = current_lt;
        }
    }

    vector<int> adj(n - 1, 0);
    for (int i = 0; i < n - 1; i++) {
        adj[i] = a[i + 1] > a[i];
    }

    vector<int> prefix_adj(n, 0);
    for (int i = 1; i < n; i++) {
        prefix_adj[i] = prefix_adj[i - 1] + adj[i - 1];
    }

    int min_delta = 0;
    int best_l = 1, best_r = 1;

    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            int delta;
            if (l == r) {
                delta = 0;
            } else {
                int count_gt = pre_gt[l][r];
                int count_lt = pre_lt[l][r];
                int sum_adj = prefix_adj[r] - prefix_adj[l + 1];
                delta = (count_gt - count_lt) - sum_adj;
            }

            if (delta < min_delta || (delta == min_delta && (l + 1 < best_l || (l + 1 == best_l && r + 1 < best_r)))) {
                min_delta = delta;
                best_l = l + 1;
                best_r = r + 1;
            }
        }
    }

    cout << best_l << " " << best_r << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cout<<(0^0)<<endl;
    return 0;
}