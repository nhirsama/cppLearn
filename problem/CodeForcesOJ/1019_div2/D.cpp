// D
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
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    int ro = 0;
    while ((1 << ro) < n) ro++;
    std::vector<int> p(n + 1);
    int low = 1, high = n;
    std::vector<int> upp(n);
    for (int i = 0; i < n; i++) upp[i] = i + 1;
    for (int k = 1; k <= ro; k++) {
        std::vector<int> nxt, rm;
        nxt.reserve(upp.size());
        rm.reserve(upp.size());
        for (int i: upp) {
            if (a[i] == k) rm.push_back(i);
            else nxt.push_back(i);
        }
        int m = rm.size(), ptr = 0;
        bool odd = (k & 1);
        for (int s: nxt) {
            while (ptr < m && rm[ptr] < s) {
                if (odd) p[rm[ptr]] = high--;
                else p[rm[ptr]] = low++;
                ptr++;
            }
        }
        for (int j = m - 1; j >= ptr; --j) {
            if (odd) p[rm[j]] = high--;
            else p[rm[j]] = low++;
        }
        upp = nxt;
        if (upp.size() <= 1) break;
    }
    p[upp[0]] = low;
    for (int i = 1; i <= n; i++) {
        std::cout << p[i] << " \n"[i == n];
    }
}

signed main() {
    IOS;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
    }
    i32 T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
