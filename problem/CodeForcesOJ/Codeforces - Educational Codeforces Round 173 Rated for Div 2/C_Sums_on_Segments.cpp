//  C. Sums on Segments
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
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int l1 = 0, r1 = 0;
    int l2 = 0x3f3f3f3f, r2 = -0x3f3f3f3f;
    int pr = 0;
    int mnl = 0, mxl = 0;
    int mnr = 0x3f3f3f3f, mxr = -0x3f3f3f3f;

    for (int i = 0; i < n; i++) {
        pr += a[i];
        if (a[i] != 1 && a[i] != -1) {
            mnr = mnl;
            mxr = mxl;
            mnl = mxl = pr;
        }
        l1 = std::min(l1, pr - mxl);
        r1 = std::max(r1, pr - mnl);
        l2 = std::min(l2, pr - mxr);
        r2 = std::max(r2, pr - mnr);
        mnl = std::min(mnl, pr);
        mxl = std::max(mxl, pr);
    }
    if (l2 > r1) {
        std::cout << std::max(0,r1 - l1 + 1) + std::max(0,r2 - l2 + 1) << endl;
        for (int x = l1; x <= r1; x++) std::cout << x << ' ';
        for (int x = l2; x <= r2; x++) std::cout << x << ' ';
    } else if (r2 < l1) {
        std::cout << std::max(0,r1 - l1 + 1) + std::max(0,r2 - l2 + 1) << endl;
        for (int x = l2; x <= r2; ++x) std::cout << x << ' ';
        for (int x = l1; x <= r1; ++x) std::cout << x << ' ';
    } else {
        int L = std::min(l1, l2);
        int R = std::max(r1, r2);
        std::cout << R - L + 1 << endl;
        for (int x = L; x <= R; ++x) std::cout << x << ' ';
    }
    std::cout << endl;
}

int main() {
    IOS;
    i32 T;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
