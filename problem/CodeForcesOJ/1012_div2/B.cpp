//B
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

void nhir() {
    i64 n, m;
    std::cin >> n >> m;
    std::vector<std::string> g(n);
    std::vector st(n, std::vector<bool>(m, false));
    for (i32 i = 0; i < n; i++) {
        std::cin >> g[i];
    }
    for (i32 i = 0; i < n; i++) {
        for (i32 j = 0; j < m; j++) {
            if (g[i][j] == '1') st[i][j] = true;
            else break;
        }
    }
    for (i32 j = 0; j < m; j++) {
        for (i32 i = 0; i < n; i++) {
            if (g[i][j] == '1') st[i][j] = true;
            else break;
        }
    }
    for (i32 i = 0; i < n; i++) {
        for (i32 j = 0; j < m; j++) {
            if (g[i][j] == '1' && st[i][j]) {
            } else if (g[i][j] == '1' && st[i][j] == false) {
                std::cout << "NO" << endl;
                return;
            }
        }
    }
    std::cout << "YES" << endl;
    return;
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
