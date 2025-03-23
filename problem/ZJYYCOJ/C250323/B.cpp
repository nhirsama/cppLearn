//模板
#include <bits/stdc++.h>
using namespace std;
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef pair<i32, i32> pii;
constexpr int N = 1e5 + 10;
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all1(x) (x).begin() + 1, (x).end()

void nhir() {
    i64 n;
    cin >> n;
    vector<pii> v(n + 1);
    i64 x1, y1, t = 1;
    i64 dist = -1;
    vector<i32> ans;
    for (int i = 1; i <= n; i++) {
        cin >> v[i].x >> v[i].y;
        i64 dis = (v[i].x - v[1].x) * (v[i].x - v[1].x) + (v[i].y - v[1].y) * (v[i].y - v[1].y);
        if (dis > dist) {
            dist = dis;
            ans.clear();
            ans.push_back(i);
        }
        else if (dis == dist) {
            ans.push_back(i);
        }
    }
    for (auto i: ans) {
        i32 j = 2;
        for (; j <= n; j++) {
            if (j == i) continue;
            i64 dis = (v[j].x - v[i].x) * (v[j].x - v[i].x) + (v[j].y - v[i].y) * (v[j].y - v[i].y);
            if (dis > dist) {
                break;
            }
        }
        if (j == n + 1) {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
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
