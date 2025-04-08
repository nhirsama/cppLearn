//B
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
    std::string n;
    std::cin >> n;
    i32 cnt = 0;
    i32 max = 0;
    for (i32 i = 0; i < n.size(); i++) {
        if (n[i] == '0') {
            cnt++;
        } else {
            if (cnt + 1 > max) {
                max = cnt + 1;
            }
        }
    }
    std::cout << n.size() - max << endl;
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
