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
    i32 next[10]{0};
    bool end = false;
};

void nhir() {
    std::vector<node> trie(1);
    i32 m;
    std::cin >> m;
    i64 fz = 0;
    i64 fm = 1000000000000000;
    for (i32 i = 0; i < m; i++) {
        std::string s;
        std::cin >> s;
        i32 p = 0;
        bool skip = false;
        for (i32 j = 0; j < s.size(); j++) {
            if (trie[p].end) {
                skip = true;
                break;
            }
            int idx = s[j] - '0';
            if (trie[p].next[idx] != 0)
                p = trie[p].next[idx];
            else {
                trie[p].next[idx] = trie.size();
                trie.push_back(node());
                p = trie[p].next[idx];
            }
        }
        if (!skip) {
            trie[p].end = true;
        }
    }
    std::vector<i64> pow10(16, 1);
    for (int i = 1; i <= 15; i++) {
        pow10[i] = pow10[i - 1] * 10;
    }

    auto dfs = [&](auto &&self, i32 p, i32 cnt) -> void {
        if (trie[p].end) {
            fz += pow10[15 - cnt];
            return;
        }
        for (auto i: trie[p].next) {
            if (i)
                self(self, i, cnt + 1);
        }
    };
    dfs(dfs, 0, 0);
    i64 gcd = std::gcd(fz, fm);
    std::cout << fz / gcd << '/' << fm / gcd << endl;
}

signed main() {
    IOS;
    i32 T = 1;
    while (T--) nhir();
    return 0;
}
