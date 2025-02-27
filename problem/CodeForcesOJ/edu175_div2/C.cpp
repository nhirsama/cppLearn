#define LOCAL
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define x first
#define y second
#define endl '\n'
#define space << ' '
typedef pair<int, char> pic;

void Solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string ts;
    bool flag = (s[0] == 'R'); //t是红，f是蓝
    int max1 = 0;
    vector<int> v;
    string aaa;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        bool bbb = (s[i] == 'R');
        if (bbb == flag) {
            if (max1 < a) {
                max1 = a;
                ts = s.substr(i, 1);
            }
        } else {
            aaa+=ts;
            ts = s.substr(i, 1);
            v.push_back(max1);
            max1 = a;
            flag = bbb;
        }
    }
    if (ts[0] == 'B') {
        aaa.append(ts);
        v.push_back(max1);
    }

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
