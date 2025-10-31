//
// Created by ling on 2025/10/31.
//
#include <bits/stdc++.h>

struct fano {
    int n;
    std::vector<std::pair<int, char> > v;
    std::vector<int> pre;

    fano(const std::string &s) {
        std::map<char, int> mp;
        for (auto i: s) {
            mp[i]++;
        }
        n = mp.size();
        for (auto &[x,y]: mp) v.emplace_back(y, x);
        std::ranges::sort(v, std::greater<>());
        pre.resize(n + 1);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + v[i].first;
        }
    }

    void build(int l, int r, const std::string &s) {
        if (l >= r || l >= v.size()) return;
        if (r - l == 1) {
            std::cout << v[l].second << ':' << s << '\n';
            return;
        };

        // 二分法找到划分点
        int left = l, right = r;
        int total = pre[r] - pre[l];
        while (left < right) {
            int mid = (left + right) / 2;
            if ((pre[mid] - pre[l]) * 2 >= total) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        // 递归分组
        build(l, left, s + "0");
        build(left, r, s + "1");
    }

    void build() {
        build(0, n, "");
    }
};

int main() {
    std::string s;
    std::cin >> s;
    fano fano(s);
    fano.build();
}
