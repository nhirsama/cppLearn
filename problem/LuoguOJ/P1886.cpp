//P1886 滑动窗口 /【模板】单调队列
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define x first
#define y second

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    deque<pair<ll, ll> > qma, qmi;
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n + 1);
    for (int i = 1; i < k; i++) {
        ll x;
        cin >> x;
        while (!qma.empty() && x >= qma.back().x) {
            qma.pop_back();
        }
        qma.push_back({x, i});
        while (!qmi.empty() && x <= qmi.back().x) {
            qmi.pop_back();
        }
        qmi.push_back({x, i});
    }
    vector<pair<int, int> > ans;
    for (int i = k; i <= n; i++) {
        ll x;
        cin >> x;
        while (!qma.empty() && x >= qma.back().x) {
            qma.pop_back();
        }
        qma.push_back({x, i});
        while (!qmi.empty() && x <= qmi.back().x) {
            qmi.pop_back();
        }
        qmi.push_back({x, i});
        while (qma.front().y <= i - k) qma.pop_front();
        while (qmi.front().y <= i - k) qmi.pop_front();
        ans.push_back({qmi.front().x, qma.front().x});
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].x << (i < ans.size() - 1 ? ' ' : '\n');
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].y << (i < ans.size() - 1 ? ' ' : '\n');
    }
    return 0;
}
