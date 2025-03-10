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
    vector<pair<char, int> > arr(n + 3), arr2(n + 3);
    vector<pii> upd1(n + 3), upd2(n + 3);
    upd1[0] = pii(1, 0);
    upd2[0] = pii(1, 0);
    for (int i = 1; i <= n; i++) {
        char op1, op2;
        int a, b;
        cin >> op1 >> a >> op2 >> b;
        arr[i] = pii(op1, a);
        arr2[i] = pii(op2, b);
    }
    upd1[n + 1] = pii(1, 0);
    upd2[n + 1] = pii(1, 0);
    ll ans1 = 1, ans2 = 1;
    for (int i = n; i; i--) {
        if (arr[i].x == '+') {
            upd1[i] = {upd1[i + 1].x, arr[i].y};
        }
        if (arr[i].x == 'x') {
            upd1[i] = {upd1[i + 1].x * arr[i].y, 0};
        }
        if (arr2[i].x == '+') {
            upd2[i] = {upd2[i + 1].x, arr2[i].y};
        }
        if (arr2[i].x == 'x') {
            upd2[i] = {upd2[i + 1].x * arr2[i].y, 0};
        }
    }
    ans1 = upd1[1].x;
    ans2 = upd2[1].x;
    for (int i = 1; i <= n; i++) {
        if (upd1[i].y) {
            if (upd1[i + 1].x > upd2[i + 1].x) {
                ans1 += upd1[i].y * upd1[i + 1].x;
            } else {
                ans2 += upd1[i].y * upd2[i + 1].x;
            }
        }
        if (upd2[i].y) {
            if (upd1[i + 1].x > upd2[i + 1].x) {
                ans1 += upd2[i].y * upd1[i + 1].x;
            } else {
                ans2 += upd2[i].y * upd2[i + 1].x;
            }
        }
    }
    cout << ans1 + ans2 << endl;
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
