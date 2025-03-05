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

void Solve() {
    int n;
    cin >> n;
    vector<int> v(n + 1);
    priority_queue<int, vector<int>, greater<int> > p;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (v[x] == 1) p.push(x);
        else v[x]++;
    }
    sort(v.begin() + 1, v.end());
    int cnt = 0;
    bool flag = false;
    for (int i = 0; i <= n; i++) {
        if (flag) cout << -1 << ' ';
        else if (!v[i]) {
            cout << cnt << ' ';
        } else {
            if (p.size() && p.top() < i) {
                cnt += i-p.top()-1;
                cout<<cnt<<' ';
                p.pop();
            } else {
                flag = true;
                cout << -1 << ' ';
            }
        }
    }
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
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
