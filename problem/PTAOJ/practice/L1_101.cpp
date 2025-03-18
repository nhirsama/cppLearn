//L1-101 别再来这么多猫娘了！
#include <bits/stdc++.h>
using namespace std;
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef pair<i32, i32> pii;
constexpr int N = 1e5 + 10;
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all1(x) (x).begin() + 1, (x).end()
#define int long long

void nhir() {
    i32 n, cnt = 0;
    cin >> n;
    vector<string> xx;
    for (i32 i = 0; i < n; i++) {
        string s;
        cin >> s;
        xx.push_back(s);
    }
    i32 k;
    cin >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    string ans;
    for (const auto& ss: xx) {
        for (i32 i = 0; i < s.size(); i++) {
            if (s.substr(i, ss.size()) == ss) {
                ans.append("-");
                i += ss.size() - 1;
                cnt++;
            } else {
                ans.push_back(s[i]);
            }
        }
        s = ans;
        ans = "";
    }
    if (k > cnt) {
        for (auto c:s) {
            if (c == '-') {
                cout<<"<censored>";
            }
            else cout<<c;
        }
    } else {
        cout << cnt << endl;
        cout << "He Xie Ni Quan Jia!";
    }
    cout<<endl;
}

signed main() {
    i32 t = 1;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        cin >> t;
    }
    while (t--) nhir();
    return 0;
}
