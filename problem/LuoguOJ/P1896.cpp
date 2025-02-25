//P1896 [SCOI2005] 互不侵犯
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define endl '\n'
ll dp[15][1 << 11][120], n, king;
vector<int> vll, vcntll;

int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> king;
    for (int i = 0; i < (1 << n); i++) {
        if ((i << 1) & i) continue;
        int t = i;
        int cnti = 0;
        while (t) {
            cnti += (t & 1);
            t >>= 1;
        }
        vll.push_back(i);
        vcntll.push_back(cnti);
    }
    for (ll i = 0; i < vll.size(); i++) {
        if (vcntll[i] > king)continue;
        dp[1][vll[i]][vcntll[i]] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < vll.size(); j++) {
            for (int k = 0; k < vll.size(); k++) {
                if (vll[j] & vll[k])continue;
                if (((vll[j] | vll[k]) << 1) & (vll[j] | vll[k]))continue;
                for (int a = 0; a + vcntll[k] <= king; a++) {
                    dp[i][vll[k]][a + vcntll[k]] += dp[i - 1][vll[j]][a];
                }
            }
        }
    }
    ll ans = 0;
    for (const int i: vll) {
        ans += dp[n][i][king];
        // cout << n << ' ' << i << ' ' << ans << endl;
    }
    cout << ans;
    return 0;
}
