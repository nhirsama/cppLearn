//P1281 书的复制
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define x first
#define y second
#define endl '\n'
#define space << ' '
typedef pair<int, int> pii;

inline ll read() {
    ll ans = 0;
    bool flag = false;
    char c = cin.get();
    while (c < '0' || c > '9') {
        if (c == '-') flag = true;
        c = cin.get();
    }
    while (c >= '0' && c <= '9') ans = (ans << 3) + (ans << 1) + (c ^ '0'), c = cin.get();
    if (flag) return -ans;
    return ans;
}

int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll m, k;
    cin >> m >> k;
    ll l = 1, r = 0;
    vector<ll> arr(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> arr[i];
        r += arr[i];
        l = max(arr[i],l);
    }
    auto check = [&](ll mid) {
        ll cnt = 1, sum = 0;
        for (int i = 1; i <= m; i++) {
            if (sum + arr[i] <= mid) sum += arr[i];
            else cnt++, sum = arr[i];
        }
        return cnt > k;
    };
    while (l < r) {
        ll mid = (l + r) >> 1;
        if (check(mid)) l = mid + 1;
        else r = mid;
    }
    //cout << l << endl;
    vector<pair<int, int> > aa(k + 2);
    auto ans = [&]() {
        ll cnt = k, sum = 0;
        aa[k].y = m;
        aa[1].x = 1;
        for (int i = m; i; i--) {
            if (sum + arr[i] <= r) sum += arr[i];
            else {
                aa[cnt--].x = i + 1;
                aa[cnt].y = i;
                sum = arr[i];
            }
        }
    };
    ans();
    for (int i = 1; i <= k; i++) {
        cout << aa[i].x << ' ' << aa[i].y << endl;
    }
    return 0;
}
