//模板
#include <bits/stdc++.h>
using namespace std;
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef std::pair<i64, i64> pii;
constexpr int N = 1e5 + 10;
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all1(x) (x).begin() + 1, (x).end()
#define int long long
i32 dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
i32 dy[] = {1, -1, 0, 1, -1, 0, 1, -1};

void nhir() {
    i64 x,y;
    std::cin >> x >> y;
    std::set<pii> s;
    i64 id = 0, cd = 0;
    auto bfs = [&]()-> bool {
        std::queue<pii> q;
        q.push(pii(x,y));
        s.insert(pii(x,y));
        while (!q.empty()) {
            i64 xx = q.front().x;
            i64 yy = q.front().y;
            q.pop();

            if (xx == yy) return true;
            id++;
            for (i32 i = 0; i < 8; i++) {
                i64 vx = xx + dx[i];
                i64 vy = yy + dy[i];
                if (std::gcd(vx, vy) == 1) {
                    continue;
                }
                id++;
                if (s.find(pii(vx, vy)) != s.end()) {
                    continue;
                }
                q.push(pii(vx, vy));
                s.insert(pii(vx, vy));
            }
            if (cd == 0) cd = id;
        }
        return false;
    };

    if (bfs()) {
        cout << "0/1\n";
    } else {
        i64 gcd = std::gcd(id, cd);
        cout << cd / gcd << '/' << id / gcd << endl;
    }
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
