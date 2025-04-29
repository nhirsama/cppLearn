//  E. Wolf
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = int;
using pii = std::pair<i32, i32>;
constexpr int N = 1e5 + 10;
constexpr int mod = 1e9 + 7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void nhir() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> v(n + 1), vp(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> v[i];
        vp[v[i]] = i;
    }
    while (q--) {
        int l, r, k;
        std::cin >> l >> r >> k;
        int p = vp[k];
        //        for (int i = l; i <= r; i++) {
        //            if (v[i] == k) p = i;
        //        }
        if (p < l || p > r) {
            std::cout << -1 << ' ';
            continue;
        }
        int b = 0, nb = 0, s = 0, ns = 0, cnt = 0;
        int mid;
        do {
            mid = (l + r) >> 1;
            if (v[mid] == k) break;
            if (p < mid && v[mid] > k) b++;
            else if (p > mid && v[mid] < k) s++;
            else if (p < mid && v[mid] < k) nb++;
            else ns++;
            //            if(p<mid){
            //                nb++;
            //            }
            //            else ns++;
            //            if(v[mid]<k) s++;
            //            else b++;
            if (mid > p) r = mid - 1;
            else l = mid + 1;
        } while (v[mid] != k);
        if (nb > n - k - b || ns > k - 1 - s) {
            std::cout << -1 << ' ';
            continue;
        }
        //        nb = std::abs(nb-b);
        //        ns = std::abs(ns-s);
        cnt += std::abs(nb - ns) * 2 + std::min(ns, nb) * 2;
        std::cout << cnt << ' ';
    }
    std::cout << endl;
}

signed main() {
    IOS;
    i32 T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
