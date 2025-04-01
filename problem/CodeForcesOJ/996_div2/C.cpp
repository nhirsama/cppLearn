//C
#include <bits/stdc++.h>
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef std::pair<i32, i32> pii;
constexpr int N = 1e5 + 10;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void nhir() {
    i64 n, m;
    std::cin >> n >> m;
    std::vector arr(n + 1, std::vector<i64>(m + 1));
    std::string s;
    std::cin >> s;
    for (i32 i = 1; i <= n; i++) {
        for (i32 j = 1; j <= m; j++) {
            std::cin >> arr[i][j];
            arr[i][0] += arr[i][j];
            arr[0][j] += arr[i][j];
        }
    }
    i64 max = 0;
    // for (i32 i = 1; i <= n; i++) max = std::max(max, arr[i][0]);
    // for (i32 i = 1; i <= m; i++) max = std::max(max, arr[0][i]);
    i32 x = 1,y = 1;
    for (i32 i = 0; i < s.size(); i++) {
        if (s[i] == 'D') {
            arr[x][y] = max - arr[x][0];
            arr[0][y] += arr[x][y];
            arr[x][0] += arr[x][y];
            x++;
        } else {
            arr[x][y] = max - arr[0][y];
            arr[x][0] += arr[x][y];
            arr[0][y] += arr[x][y];
            y++;
        }
    }
    arr[n][m] = max - arr[n][0];
    for (i32 i = 1; i <= n; i++) {
        for (i32 j = 1; j <= m; j++) {
            std::cout << arr[i][j] << ' ';
        }
        std::cout << endl;
    }
}

signed main() {
    IOS;
    i32 T = 1;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
    }
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
