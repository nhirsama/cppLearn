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
i32 dx[] = {0,0,1,1,1,-1,-1,-1};
i32 dy[] = {1,-1,0,1,-1,0,1,-1};
void nhir() {
    i64 x,y;
    std::cin>>x>>y;
    std::map<pii,i32> m;
    auto dfs = [&] (auto self,i64 ux,i64 uy)->bool {
        if (ux == uy) return true;
        if (std::gcd(ux,uy) == 1)return false;
        for (i32 i = 0;i<8;i++) {
            i64 vx = ux+dx[i];
            i64 vy = uy+dy[i];
            if (m.find(pii(vx,vy)) == m.end()) {

            }
        }

    };

}

signed main() {;
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
