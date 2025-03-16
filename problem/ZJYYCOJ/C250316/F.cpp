//模板
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

void solve() {
    i32 n;
    i64 l = 0, r = 0,x = 0;
    string s;
    cin >> s;
    n = s.length();
    s = "#" + s;
    string ans;
    vector dp(n + 1, vector<i64>(3));
    for (int i = 1; i <= n; i++) {
        if (s[i] == '(') {
            dp[i][0] = dp[i - 1][0] + 1;
            dp[i][1] = dp[i - 1][1];
            dp[i][2] = dp[i - 1][2];
            l++;
        } else if (s[i] == ')') {
            r++;
            dp[i][1] = dp[i - 1][1] + 1;
            dp[i][0] = dp[i - 1][0];
            dp[i][2] = dp[i - 1][2];
            if (dp[i][1] > dp[i][0]) {
                dp[i][2]--;
                dp[i][0]++;
                if (dp[i][2] < 0) {
                    cout << "No solution!" << endl;
                    return;
                }
            }
        } else {
            x++;
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][1];
            dp[i][2] = dp[i - 1][2] + 1;
        }
    }
    if (dp[n][0] - dp[n][1] > 0) {
        dp[n][2] -= dp[n][0] - dp[n][1];
        dp[n][1] = dp[n][0];
        if (dp[n][2] < 0) {
            cout << "No solution!" << endl;
            return;
        }
    }
    for (i32 i = 1; i <= n; i++) {
        if (s[i] == '(') {
            ans+= '(';
            dp[n][0]--;
            l--;
        }
        else if (s[i] == ')') {
            ans+= ')';
            dp[n][1]--;
            r--;
        }
        else if (s[i] == '*') {
            if (dp[n][0] > l) {
                ans+= '(';
                dp[n][0]--;
            } else if (dp[n][2] > 0) {
                dp[n][2]--;
            } else {
                ans+= ')';
                dp[n][1]--;
            }
            x--;
        }
    }
    i32 num = 0;
    for (auto c:ans) {
        if (c == '(') num++;
        else if (c == ')') num--;
        if (num<0) {
            cout << "No solution!" << endl;
            return;
        }
    }
    cout<<ans;
    cout << endl;
    //cout << dp[n][0] + dp[n][1] << endl;
}

signed main() {
    IOS;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
