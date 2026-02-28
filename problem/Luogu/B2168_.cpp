//  B2168 【模板】哈夫曼编码
//  22:11
#include <bits/stdc++.h>

#include <utility>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"Luogu"};

struct huffman {
    std::string ch;
    int64 freq;
    int64 left, right;

    huffman(std::string ch, int64 freq) : ch(std::move(ch)), freq(freq), left(-1), right(-1) {
    }
};


void nhir() {
    struct node {
        int64 id, cnt;
        std::string s;
    };
    int n;
    std::cin >> n;
    std::vector<node> v(n);
    std::priority_queue<huffman, std::vector<huffman>, decltype([](const huffman &a, const huffman &b)-> bool {
        return a.freq > b.freq;
    })> pq;
    for (int i = 0; i < n; i++) {
        std::cin >> v[i].s >> v[i].cnt;
        v[i].id = i;
        pq.emplace(v[i].s, v[i].cnt);
    }
    std::vector<huffman> huf;
    while (pq.size() > 1) {
        huf.push_back(pq.top());
        pq.pop();
        huf.push_back(pq.top());
        pq.pop();
        huffman parent("", huf[huf.size() - 1].freq + huf[huf.size() - 2].freq);
        parent.left = huf.size() - 2;
        parent.right = huf.size() - 1;
        pq.push(parent);
    }
    huf.push_back(pq.top());
    pq.pop();
    std::map<std::string, std::string> m;
    auto dfs = [&](auto &&self, int64 f, std::string s)-> void {
        if (huf[f].ch != "") m[huf[f].ch] = s;
        if (huf[f].left != -1) {
            self(self, huf[f].left, s + '0');
        }
        if (huf[f].right != -1) {
            self(self, huf[f].right, s + '1');
        }
    };

    dfs(dfs, huf.size() - 1, "");
    if (v.size() == 1) m[v[0].s] = "0";
    for (auto &i: v) {
        std::cout << i.s << ' ' << m[i.s] << '\n';
    }
}


signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    if (OJ_NAME != "AtCoder")
        // std::cin >> T;
        while (T--) nhir();
    return 0;
}