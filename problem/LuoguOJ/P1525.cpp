//模板
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
    std::vector<i64> root(n * 2 + 10);
    for (i32 i = 1; i <= n * 2 + 5; i++)root[i] = i;
    struct node {
        i64 a, b, w;
    };
    std::vector<node> arr(m);
    for (auto &i: arr)std::cin >> i.a >> i.b >> i.w;
    std::sort(all(arr), [](auto a, auto b) { return a.w > b.w; });
    auto find = [&root](auto &&self, i32 u)-> i32 {
        return root[u] == u ? u : root[u] = self(self, root[u]);
    };
    for (auto i: arr) {
        if (find(find, i.a) == find(find, i.b)) {
            std::cout << i.w << endl;
            return;
        }
        root[find(find, i.a)] = find(find, i.b + n);
        root[find(find, i.b)] = find(find, i.a + n);
    }
    std::cout << 0 << endl;
}

signed main() {
    IOS;
    i32 T = 1;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
        std::cin >> T;
    }

    while (T--) nhir();
    return 0;
}
