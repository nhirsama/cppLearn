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

signed main() {
    IOS;
    i64 n;
    cin >> n;
    string s;
    cin >> s;
    i32 a = 0;
    vector<vector<i32> > dp(4);
    vector<i32> arr;
    dp[0].push_back(0);
    arr.push_back(0);
    for (i32 i = 0; i < n; i++) {
        if (s[i] == '0') a ^= 1;
        else a ^= 2;
        dp[a].push_back(i + 1);
        arr.push_back(a);
    }
    i64 cnt = 0;
    for (i32 i = 1; i <= n; i++) {
        auto p = upper_bound(dp[arr[i]].begin(), dp[arr[i]].end(), i);
        if (p != dp[arr[i]].end() && *p <= n) {
            cnt++;
        }
    }
    cout << fixed << setprecision(10) << (double) (cnt) / n << endl;
    return 0;
}
