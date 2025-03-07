//P1182 数列分段 Section II
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define x first
#define y second
#define endl '\n'
#define space << ' '
typedef pair<int, int> pii;

int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("inAndoutFile/P1182_4.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m;
    ll upper = 0, lower = 0;
    cin >> n >> m;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        upper += arr[i];
        lower = max(lower, 1ll * arr[i]);
    }
    auto check = [&](ll mid) {
        int cnt = 1, sum = 0;
        for (int i = 1; i <= n; i++) {
            if (sum + arr[i] <= mid)sum += arr[i];
            else sum = arr[i], cnt++;
        }
        if (cnt <= m) return false;
        return true;
    };
    while (lower < upper) {
        ll mid = (upper + lower) >> 1;
        if (check(mid)) lower = mid + 1;
        else upper = mid;
    }
    cout << upper << endl;
    return 0;
}