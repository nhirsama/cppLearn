#define LOCAL
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define x first
#define y second
#define endl '\n'
#define space << ' '
typedef pair<int, int> pii;
unordered_set<long long> se;

void Solve() {
    long long n;
    long long sum = 0;
    queue<ll> q;
    cin >> n;
    ll aaa = (1 + n) * n / 2;
    if (n == 1) cout << -1;
    else if (se.find(aaa) != se.end()) cout << -1;
    else {
        for (ll i = n; i >= 1; i--) {
            if (se.find(sum + i) == se.end()) {
                cout << i space;
                sum += i;
            } else {
                q.push(i);
            }
        }
    }
    int cnt = 0;
    while (!q.empty() && cnt <= q.size()) {
        ll i = q.front();
        q.pop();
        if (se.find(sum + i) == se.end()) {
            cout << i space;
            sum += i;
            cnt = 0;
        } else {
            q.push(i);
            cnt++;
        }
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    for (long long t = 1; t <= 500000; t++) {
        se.insert(t * t);
    }
    int T;
    cin >> T;
    while (T--) {
        Solve();
    }
    return 0;
}
