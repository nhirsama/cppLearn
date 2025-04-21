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
    int n;
    std::string s;
    std::cin >> n >> s;
    int cnt = 0;
    s = '0' + s;
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] != s[i]) cnt++;
    }
    int cnt01 = 0, cnt10 = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '0' && s[i] == '1') cnt01++;
        if (s[i - 1] == '1' && s[i] == '0') cnt10++;
    }
    int aa = 0;
    if (cnt01 >= 2 || cnt10 >= 2) {
        aa = 2;
    } else {
        for (int i = 1; i <= n; i++) {
            if (s[i - 1] != s[i] && s[i - 1] == s[n]) {
                aa = 1;
                break;
            }
        }
    }
    std::cout << n + cnt - aa << "\n";
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
