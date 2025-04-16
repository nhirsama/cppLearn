//  G. Chimpanzini Bananini
#include <bits/stdc++.h>

using i64 = unsigned long long int;
using i32 = int;
using pii = std::pair<i32, i32>;
constexpr int N = 1e5 + 10;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void nhir() {
    i64 q, sum = 0, zsum = 0, nsum = 0, cnt = 0;
    std::deque<i64> d, dn;
    std::cin >> q;
    while (q--) {
        i32 op;
        std::cin >> op;
        if (op == 1) {
            i64 t = d.back();
            d.pop_back();
            zsum += (sum - t) - t * (cnt - 1);
            d.push_front(t);

            t = dn.front();
            dn.pop_front();
            nsum -= (sum - t) - t * (cnt - 1);
            dn.push_back(t);
        } else if (op == 2) {
            std::swap(zsum, nsum);
            std::swap(d, dn);
        } else if (op == 3) {
            cnt++;
            i64 tt;
            std::cin >> tt;
            d.push_back(tt);
            dn.push_front(tt);
            zsum += tt * cnt;
            nsum+=sum;
            nsum+=tt;
            sum += tt;
            //nsum += sum;
        }
        std::cout << zsum << endl;
    }
}

signed main() {
    IOS;
    i32 T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
