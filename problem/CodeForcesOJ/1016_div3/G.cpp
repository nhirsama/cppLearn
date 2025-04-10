//G
#include <bits/stdc++.h>
using i64 = long long int;
using i32 = int;
using pii = std::pair<i32, i32>;
constexpr int N = 1e5 + 10;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()

struct node {
    i32 next[2] = {-1, -1};
    i32 num = -1;
};

void nhir() {
    i32 n, k;
    std::cin >> n >> k;
    std::vector<i32> v(n);
    for (auto &i: v) std::cin >> i;
    std::vector<node> trie(1);
    auto add = [&](i32 ve, i32 idx) {
        i32 index = 0;
        trie[index].num = std::max(trie[index].num, idx);
        for (i32 j = 29; ~j; j--) {
            i32 bit = (ve >> j) & 1;
            if (trie[index].next[bit] == -1) {
                trie[index].next[bit] = trie.size();
                trie.push_back({});
            }
            index = trie[index].next[bit];
            trie[index].num = std::max(trie[index].num, idx);
        }
    };
    auto find = [&](i32 ve) {
        i32 index = 0;
        i32 ans = -1;
        for (i32 i = 29; ~i; i--) {
            auto &next = trie[index].next;
            int x_bit = (ve >> i) & 1;
            int k_bit = (k >> i) & 1;
            if (k_bit) {
                // ans = std::max(ans, trie[index].num);
                if (next[x_bit ^ 1] != -1) {
                    index = next[x_bit ^ 1];
                } else return ans;
            } else {
                if (next[x_bit ^ 1] != -1) {
                    ans = std::max(ans, trie[next[x_bit ^ 1]].num);
                }
                if (next[x_bit] != -1) {
                    index = next[x_bit];
                } else return ans;
            }
        }
        ans = std::max(ans, trie[index].num);
        return ans;
    };

    i32 ans = n + 1;
    for (i32 i = 0; i < n; i++) {
        add(v[i], i);
        i32 y = find(v[i]);
        if (y != -1) {
            ans = std::min(ans, i - y + 1);
        }
    }
    if (ans == n + 1) {
        std::cout << -1 << endl;
    } else {
        std::cout << ans << endl;
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
