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
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n), b(n);
    for (auto &i: a) std::cin >> i;
    for (auto &i: b) std::cin >> i;
    if (std::count(all(b), -1) == n) {
        int max = *max_element(a.begin(), a.end());
        int min = *min_element(a.begin(), a.end());
        if (max > min + k) {
            std::cout << 0 << '\n';
        } else {
            std::cout << min + k - max + 1 << '\n';
        }
    } else {
        int sum = -1;
        for (int i = 0; i < n; i++) {
            if (b[i] != -1) {
                if (sum == -1) {
                    sum = b[i] + a[i];
                } else if (sum == b[i] + a[i]) {
                } else {
                    std::cout << 0 << endl;
                    return;
                }
            }
        }
        for (int j = 0; j < n; ++j) {
            if (b[j] == -1) {
                int bj = sum - a[j];
                if (bj < 0 || bj > k) {
                    std::cout << 0 << endl;
                    return;
                }
            }
        }
        std::cout << 1 << endl;
        return;
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
