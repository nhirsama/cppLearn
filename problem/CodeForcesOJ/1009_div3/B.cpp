#define LOCAL
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define x first
#define y second
#define endl '\n'
#define space << ' '
typedef pair<int, int> pii;

void Solve() {
    int n;
    queue<ll> q;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        q.push(x);
    }
    while (q.size() > 1) {
        ll x = q.front();
        q.pop();
        ll y = q.front();
        q.pop();
        q.push(x+y-1);
    }
    cout << q.front() << endl;
}

int main() {
    IOS
    #ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    //freopen("Code.out", "w", stdout);
    #endif
    int T;
    cin >> T;
    while (T--) {
        Solve();
    }
    return 0;
}
