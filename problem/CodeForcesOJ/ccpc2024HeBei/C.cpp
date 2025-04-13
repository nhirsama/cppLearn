#include <bits/stdc++.h>
using namespace std;

using PII = pair<int, int>;
constexpr int INF = 1e9 + 17;

void IOS() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

struct node {
    int l, r, order;

    bool operator <(const node &other) const {
        if (other.r != r) return r < other.r;
        return l < other.l;
    }
};

// bool cmp(const node &a, const node &b) {
//     if (a.r != b.r) return a.r < b.r;
//     return a.l < b.l;
// }

void base_e() {
    int n, minx = INF, fi = 0;
    cin >> n;
    vector<node> a(n);
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].l >> a[i].r;
        a[i].order = i + 1;
        if (a[i].l == 0) {
            if (minx > a[i].r - a[i].l) {
                minx = a[i].r - a[i].l;
                fi = i;
            }
        }
    }
    a.erase(a.begin() + fi);
    priority_queue<node> heap;
    ans.push_back(fi + 1);
    int now = 1;
    sort(a.begin(), a.end());
    // for (int i = 0; i < a.size(); ++i) {
    //     cout << a[i].l << " " << a[i].r << " " << a[i].order << "\n";
    // }
    for (int i = 0; i < a.size(); ++i) {
        if (a[i].l <= now && a[i].r >= now) {
            bool tag = true;
            while (now + 1 < a[i].r && tag && !heap.empty()) {
                auto n = heap.top();
                if (n.l <= now && n.r >= now) {
                    ++now;
                    ans.push_back(n.order);
                    heap.pop();
                } else tag = false;
            }
            ans.push_back(a[i].order);
            now++;
        } else heap.push(a[i]);
    }
    while (heap.size()) {
        auto n = heap.top();
        if (n.l <= now && n.r >= now) {
            ans.push_back(n.order);
            ++now;
        }
        heap.pop();
    }
    cout << now << "\n";
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
}

int main() {
    IOS();
    base_e();
}
