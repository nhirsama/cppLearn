// D. Shop
#include <bits/stdc++.h>
using namespace std;
using i32 = long long;

struct node {
    int op, i;
    double b;
    int num;
};

void nhir() {
    int k, n, m;
    cin >> k >> n >> m;
    vector<double> a(k);
    for (int i = 0; i < k; i++) cin >> a[i];
    // 存储每个技能的最佳赋值、所有加法和所有乘法
    vector<node> bestAssign(k, {0, 0, 0.0, 0});
    vector<bool> hasAssign(k, false);
    vector<vector<node> > adds(k);
    vector<node> mults;
    // 读入并分类
    for (int idx = 1; idx <= n; idx++) {
        int op, ii;
        double b;
        cin >> op >> ii >> b;
        if (op == 1) {
            // 记录最大的赋值
            if (!hasAssign[ii - 1] || b > bestAssign[ii - 1].b) {
                bestAssign[ii - 1] = {1, ii, b, idx};
                hasAssign[ii - 1] = true;
            }
        } else if (op == 2) {
            adds[ii - 1].push_back({2, ii, b, idx});
        } else {
            mults.push_back({3, ii, b, idx});
        }
    }
    // 把赋值当作一次加法 Δ = b - a，并且只有 Δ>0 时才有意义
    for (int i = 0; i < k; i++) {
        if (hasAssign[i]) {
            double delta = bestAssign[i].b - a[i];
            if (delta > 0) {
                adds[i].push_back({1, i + 1, delta, bestAssign[i].num});
            }
        }
    }
    // 计算所有“加法→乘法”升级的倍数，并收集所有乘法升级
    vector<node> items;
    for (int i = 0; i < k; i++) {
        auto &v = adds[i];
        sort(v.begin(), v.end(), [](const node &x, const node &y) {
            return x.b > y.b;
        });
        double denom = a[i];
        for (auto &nd: v) {
            double ratio = 1.0 + nd.b / denom;
            items.push_back({nd.op, nd.i, ratio, nd.num});
            denom += nd.b;
        }
    }
    for (auto &nd: mults) {
        items.push_back(nd);
    }
    // 按倍数降序选出前 m 个，且倍数要大于 1
    sort(items.begin(), items.end(), [](const node &x, const node &y) {
        return x.b > y.b;
    });
    vector<node> ans;
    for (auto &nd: items) {
        if (ans.size() >= (size_t) m) break;
        if (nd.b <= 1.0) break;
        ans.push_back(nd);
    }
    // 最终输出按 op 升序，同 op 下按原编号升序
    sort(ans.begin(), ans.end(), [](const node &x, const node &y) {
        if (x.op != y.op) return x.op < y.op;
        return x.num < y.num;
    });
    cout << ans.size() << '\n';
    for (auto &nd: ans) {
        cout << nd.num << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    nhir();
    return 0;
}
