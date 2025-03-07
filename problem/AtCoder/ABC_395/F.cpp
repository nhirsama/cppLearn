//AT_abc395_f [ABC395F] Smooth Occlusion
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n,x, sum = 0, minn = 0x3f3f3f3f3f;
    cin >> n >> x;
    vector<ll> ui(n + 1), di(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ui[i] >> di[i];
        sum += ui[i] + di[i];
        if (ui[i] + di[i] < minn)minn = ui[i] + di[i];
    }
    ll l = 0, r = minn;
    auto check = [&](ll mid)-> bool {
        ll upper = min(ui[1], mid), lower = max(mid - di[1], 0ll);
        if (upper < lower) return false;
        for (int i = 2; i <= n; i++) {
            ll uppert = min(ui[i], mid), lowert = max(mid - di[i], 0ll);
            upper = min(upper + x, uppert), lower = max(lower - x, lowert);
            if (uppert <= lowert || upper <= lower) return false;
        }
        if (upper <= lower) return false;
        return true;
    };
    while (l < r) {
        ll mid = (l + r) >> 1;
        if (check(mid)) l = mid + 1;
        else r = mid;
    }
    cout << sum - l * n << endl;
    return 0;
}
