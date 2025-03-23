//P1955 [NOI2015] 程序自动分析
#include <bits/stdc++.h>
using namespace std;
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef pair<i32, i32> pii;
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'
#define all1(x) (x).begin() + 1, (x).end()

struct node {
    i64 x, y, w;
};

void nhir() {
    i64 n = 0;
    cin >> n;
    map<i64, i32> m;
    vector<node> v(n + 1);
    i64 cnt = 1;
    for (i32 i = 1; i <= n; i++) {
        i64 x, y, w;
        cin >> x >> y >> w;
        v[i] = {x, y, w};
        if (!m.count(x)) m[x] = ++cnt;
        if (!m.count(y)) m[y] = ++cnt;
    }
    vector<i32> ccb(cnt + 1);
    for (i32 i = 1; i <= cnt; i++) ccb[i] = i;
    //反集，cnt之前的是相等，cnt之后的是不相等
    auto find = [&](auto self, i32 root) -> i32 {
        return ccb[root] == root ? root : ccb[root] = self(self, ccb[root]);
    };
    sort(all1(v), [](node a, node b)-> bool { return a.w > b.w; });
    for (i32 i = 1; i <= n; i++) {
        i32 x = m[v[i].x];
        i32 y = m[v[i].y];
        i32 w = v[i].w;
        if (w) {
            i32 fx = find(find, x);
            i32 fy = find(find, y);
            ccb[fx] = fy;
        } else {
            if (ccb[find(find, x)] == ccb[find(find, y)]) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
    //讲个笑话，反集并查集是假做法，因为存在a！=b！=c的情况，但是可能会误将a与c合并。但是只错了一个点的一个数据
    // for (i32 i = 1; i <= n; i++) {
    //     if (v[i].w == 1) {
    //         if (find(find, ccb[m[v[i].x]+cnt]) == find(find, ccb[m[v[i].x] + cnt])) {
    //             cout << "NO" << endl;
    //             return;
    //         } else {
    //             ccb[find(find, ccb[m[v[i].x]])] == find(find, ccb[m[v[i].x]]);
    //             ccb[find(find, ccb[m[v[i].x]] + cnt)] == find(find, ccb[m[v[i].x + cnt]]);
    //         }
    //     } else {
    //         if (find(find, ccb[m[v[i].x]]) == find(find, ccb[m[v[i].x]])) {
    //             cout << "NO" << endl;
    //             return;
    //         } else {
    //             ccb[find(find, ccb[m[v[i].x] + cnt])] == find(find, ccb[m[v[i].x]]);
    //             ccb[find(find, ccb[m[v[i].x]])] == find(find, ccb[m[v[i].x] + cnt]);
    //         }
    //     }
    // }
    // cout << "YES" << endl;
}

signed main() {
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
    }
    IOS;
    i32 T;
    cin >> T;
    while (T--) nhir();
    return 0;
}
