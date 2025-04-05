//B
#include <bits/stdc++.h>
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef std::pair<i32, i32> pii;
constexpr int N = 1e5 + 10;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void nhir() {
    i32 n;
    std::cin >> n;
    std::vector<i32> v(2 * n + 1), vpre(2 * n + 1);
    std::vector<pii> vp(n + 1);
    for (i32 i = 1; i <= n; i++) {
        std::cin >> vp[i].first >> vp[i].second;
        if (vp[i].first == vp[i].second) {
            v[vp[i].second]++;
        }
    }
    for (i32 i = 1; i <= 2 * n; i++) {
        vpre[i] += (v[i] > 0) + vpre[i - 1];
    }
    std::string s;
    for (i32 i = 1; i <= n; i++) {
        if (vp[i].first == vp[i].second) {
            if (v[vp[i].second] == 1) {
                s.append("1");
            } else {
                s.append("0");
            }
        } else {
            //auto p = std::lower_bound(v.begin()+vp[i].first,v.begin()+vp[i].second+1,v[vp[i].first-1]+vp[i].second-vp[i].first+1)-v.begin();

            if (vpre[vp[i].second] - vpre[vp[i].first - 1] < vp[i].second - vp[i].first + 1) {
                s.append("1");
            } else {
                s.append("0");
            }
            // for (i32 j = vp[i].first; j <= vp[i].second; j++) {
            //     if (v[j] == 0) {
            //         s.append("1");
            //         break;
            //     }
            // }
            // if (s.size() < i) s.append("0");
        }
    }
    std::cout << s << endl;
}

signed main() {
    IOS;
    i32 T = 1;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
    }
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
