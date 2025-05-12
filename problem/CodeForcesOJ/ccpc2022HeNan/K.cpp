//
// Created by ling on 25-5-12.
//
#include <bits/stdc++.h>
using i32 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i32 n;
    std::cin >> n;
    std::vector<i32> v(n + 1);
    for (i32 i = 1; i <= n; i++) {
        std::cin >> v[i];
    }
    std::vector<bool> vis(n + 1);
    std::vector<i32> len(n + 1), d(n + 1);
    std::vector<i32> s;
    std::unordered_map<i32, std::vector<i32> > loop;
    for (i32 i = 1; i <= n; i++) {
        if (!vis[i]) {
            i32 it = i;
            while (!vis[it]) {
                s.push_back(it);
                vis[it] = true;
                it = v[it];
            }
            auto its = find(s.begin(), s.end(), it);
            if (its == s.end()) {
                i32 listlen = d[it];
                i32 looplen = len[it];
                while (!s.empty()) {
                    d[s.back()] = ++listlen;
                    len[s.back()] = looplen;
                    loop[looplen].push_back(listlen);
                    s.pop_back();
                }
                continue;
            } else {
                i32 itp = its - s.begin() + 1;
                i32 listlen = 0;
                i32 looplen = s.end() - its;
                for (i32 j = s.size() - 1; ~j; j--) {
                    d[s[j]] = j >= itp ? 0 : listlen++;
                    len[s[j]] = looplen;
                    loop[looplen].push_back(d[s[j]]);
                }
                s.clear();
            }
        }
    }
    for (auto &[x,y]: loop) {
        std::vector<i32> cnt(n + 1);
        for (auto z: y) {
            cnt[z]++;
        }
        for (i32 i = 1; i <= n; i++) cnt[i] += cnt[i - 1];
        std::swap(cnt, y);
    }
    i32 q;
    std::cin >> q;
    while (q--) {
        i32 x, y;
        std::cin >> x >> y;
        if (x == y) {
            std::cout << n << '\n';
        } else {
            if (x > y) std::swap(x, y);
            i32 z = y - x;
            //std::cout << z << std::endl;
            i32 ans = 0;
            for (auto &[i,j]: loop) {
                if (z % i)continue;
                ans += j[std::min(x, n)];
            }
            std::cout << ans << '\n';
        }
    }
}
