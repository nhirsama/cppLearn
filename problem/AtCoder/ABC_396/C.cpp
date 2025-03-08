#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define x first
#define y second
#define endl '\n'
#define space << ' '
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    priority_queue<int> h, b;
    int n, m;
    cin >> n >> m;
    ll ans = 0;
    int hcnt = 0;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        if (a >= 0) ans += a,hcnt++;
        else h.push(a);
    }
    for (int i = 1; i <= m; i++) {
        int a;
        cin >> a;
        b.push(a);
    }
    while (!b.empty() && hcnt) {
        if (b.top() >= 0) {
            ans += b.top();
            b.pop();
            hcnt--;
        } else break;
    }
    while (!b.empty() && !h.empty()) {
        if (b.top() + h.top() > 0) {
            ans += b.top() + h.top();
            b.pop();
            h.pop();
        }
        else break;
    }
    cout << ans << endl;
    return 0;
}
