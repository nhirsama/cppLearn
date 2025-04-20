//模板
#include <bits/stdc++.h>
using i64 = long long int;
using i32 = int;
using pii = std::pair<i32, i32>;
constexpr int N = 1e5 + 10;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void nhir() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> cnt(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y, z;
        std::cin >> x >> y >> z;
        cnt[z ? x : y]++;
    }
    //std::queue<pii> q;
    std::vector<pii> v;
    for (int i = 0; i < k; i++) {
        int x, y;
        std::cin >> x >> y;
        if (x == 1 || y == 1) cnt[1]++;
        else {
            if (cnt[x] < cnt[1]) cnt[x]++;
            else if (cnt[y] < cnt[1]) cnt[y]++;
            else {
                v.push_back({x, y});
            }
        }
    }
    int S = cnt[1];
    for (auto [x, y]: v) {
        int a = cnt[x], b = cnt[y];
        if (a >= S) {
            if (b + 1 > S) {
                std::cout << "NO\n";
                return;
            }
            cnt[y]++;
        } else if (b >= S) {
            if (a + 1 > S) {
                std::cout << "NO\n";
                return;
            }
            cnt[x]++;
        } else {
            if (a <= b) {
                cnt[x]++;
            } else {
                cnt[y]++;
            }
        }
    }
    // while (!q.empty()) {
    //     auto [x,y] = q.front();
    //     q.pop();
    //     if (cnt[x] < cnt[1]) cnt[x]++;
    //     else if (cnt[y] < cnt[1]) cnt[y]++;
    //     else {
    //         std::cout<<"NO\n"<<endl;
    //         return;
    //     }
    // }
    // while (!q.empty()) {
    //     auto [x,y] = q.front();
    //     if (num > q.size() + 1) {
    //         cnt[x]++;
    //         q.pop();
    //         num = 0;
    //         continue;
    //     }
    //
    //     q.pop();
    //     if (cnt[x] < cnt[y]) cnt[x]++, num = 0;
    //     else if (cnt[x] > cnt[y]) cnt[y]++, num = 0;
    //     else {
    //         num++;
    //         q.push({x, y});
    //     }
    // }
    int max = *std::max_element(1 + all(cnt));
    std::cout << (max == cnt[1] ? "YES\n" : "NO\n");
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
