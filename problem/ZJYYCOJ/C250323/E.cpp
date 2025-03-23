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
#define int long long

i64 cross(pii a, pii b) {
    // 叉乘
    return a.x * b.y - a.y * b.x;
}

i64 cross(pii p1, pii p2, pii p0) {
    // 叉乘 (p1 - p0) x(p2 - p0);
    p1.x -= p0.x;
    p1.y -= p0.y;
    p2.x -= p0.x;
    p2.y -= p0.y;
    return cross(p1, p2);
}

void nhir() {
    i64 x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    i32 a = cross({x2, y2}, {x3, y3}, {x1, y1});
    if (a < 0) cout << "Clockwise" << endl;
    else cout << "Counterclockwise" << endl;
}

signed main() {
    ;
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
