//
// Created by Origami on 25-4-13.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    std::cin >> n;
    struct node {
        int l, r, n;
    };
    vector<node> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i].l >> arr[i].r;
        arr[i].n = i + 1;
    }
    std::sort(arr.begin(), arr.end(), [](node a, node b) {
        if (a.l == b.l) return a.r < b.r;
        return a.l < b.l;
    });
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > p;
    vector<int> ans;
    int cnt = 0;
    for (int i = 0;;) {
        while (i < n && arr[i].l <= cnt) {
            p.push(pair<int, int>(arr[i].r, arr[i].n));
            i++;
        }
        if (p.empty()) break;
        while (!p.empty()) {
            if (p.top().first >= cnt) {
                cnt++;
                ans.push_back(p.top().second);
                p.pop();
                break;
            }
            p.pop();
        }
    }
    std::cout << ans.size() << endl;
    for (auto i: ans) std::cout << i << ' ';
}
