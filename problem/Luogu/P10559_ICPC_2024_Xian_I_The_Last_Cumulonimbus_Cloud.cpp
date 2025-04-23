//  P10559 [ICPC 2024 Xi'an I] The Last Cumulonimbus Cloud
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = int;
using pii = std::pair<i32, i32>;
constexpr int N = 6e5 + 10, M = 6e6 + 10;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()

inline int read() {
    int ans = 0;
    char c = std::cin.get();
    while (c < '0' || c > '9') c = std::cin.get();
    while (c >= '0' && c <= '9') ans = (ans << 3) + (ans << 1) + (c ^ '0'), c = std::cin.get();
    return ans;
}

int head[M], to[M], nxt[M], ecnt;
int head2[M], to2[M], nxt2[M], ecnt2;
int n, m, q;
// std::vector<int> g[N];
// std::vector<int> ng[N];
int rd[N];
int clouda[N], cloudb[N];
bool st[N];

inline void add(int u, int v) {
    to[ecnt] = v;
    nxt[ecnt] = head[u];
    head[u] = ecnt++;
}

inline void add2(int u, int v) {
    to2[ecnt2] = v;
    nxt2[ecnt2] = head2[u];
    head2[u] = ecnt2++;
}

void nhir() {
    n = read(), m = read(), q = read();
    ecnt = ecnt2 = 0;
    std::fill_n(head, n, -1);
    std::fill_n(head2, n, -1);
    for (int i = 0; i < m; i++) {
        int u = read()-1, v = read()-1;
        add(u, v);
        add(v, u);
        // g[u].push_back(v);
        // g[v].push_back(u);
        rd[u]++, rd[v]++;
    }
    std::queue<int> qu;
    for (int i = 0; i < n; i++) {
        if (rd[i] <= 10) qu.push(i);
    }
    while (!qu.empty()) {
        int u = qu.front();
        qu.pop();
        st[u] = true;
        for (int e = head[u]; e != -1; e = nxt[e]) {
            int v = to[e];
            if (st[v]) continue;
            add2(u, v);
            if (--rd[v] == 10) qu.push(v);
        }
        // for (auto i: g[u]) {
        //     if (st[i]) {
        //         continue;
        //     }
        //     ng[u].push_back(i);
        //     rd[i]--;
        //     if (rd[i] <= 10) qu.push(i);
        // }
        //        auto it = g[u].begin();
        //        while (it != g[u].end()) {
        //            if(st[*it]) {
        //                it = g[u].erase(it);
        //            } else {
        //                ng[u].push_back(*it);
        //                rd[*it]--;
        //                if(rd[*it]==10) qu.push(*it);
        //                ++it;
        //            }
        //        }
        //        for(auto it = g[u].begin();it!=g[u].end();it++){
        //            if(st[*it]) {
        //                g[u].erase(it);
        //                continue;
        //            }
        //            ng[u].push_back(*it);
        //            rd[*it]--;
        //            if(rd[*it]<=10) qu.push(*it);
        //        }
    }
    for (int i = 0; i < n; i++) {
        clouda[i] = read();
    }
    for (int u = 0; u < n; u++) {
        for (int e = head2[u]; e != -1; e = nxt2[e]) {
            cloudb[to2[e]] += clouda[u];
        }
        // for (auto j: ng[i]) {
        //     cloudb[j] += clouda[i];
        // }
    }
    while (q--) {
        int op = read();
        if (op == 1) {
            int x = read()-1, v = read();
            clouda[x] += v;
            for (int e = head2[x]; e != -1; e = nxt2[e]) {
                cloudb[to2[e]] += v;
            }
            // for (auto j: ng[x]) {
            //     cloudb[j] += v;
            // }
        } else {
            int x = read()-1;
            i64 cnt = cloudb[x];
            for (int e = head2[x]; e != -1; e = nxt2[e]) {
                cnt += clouda[to2[e]];
            }
            // for (auto j: ng[x]) {
            //     cnt += clouda[j];
            // }
            std::cout << cnt << endl;
        }
    }
}

signed main() {
    IOS;
    i32 T = 1;
    while (T--) nhir();
    return 0;
}
