//  B. Good Start
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr i64 inf_i64 = 0x3f3f3f3f3f3f3f3f;

void nhir() {
    i32 w, h, a, b;
    std::cin >> w >> h >> a >> b;
    i32 x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    if (x1 > x2) {
        std::swap(x1, x2);
        std::swap(y1, y2);
    }
    x1 += a - 1;
    i32 dx = x2 - x1 - 1;
    i32 dy = std::max(y1, y2) - std::min(y1, y2) - b;
//    std::cout << dx << ' ' << dy << endl;
    if (dx >= 0 && dx % a == 0) {
        std::cout << "Yes\n";
        return;
    }
    if (dy >= 0 && dy % b == 0) {
        std::cout << "Yes\n";
        return;
    }
//    if ((y1 <= y2 && y2 <= y1 + b - 1) || (y1 <= y2 + b - 1 && y2 + b - 1 <= y1 + b - 1)) {
//        if ((x2 - x1) % a == 0) {
//            std::cout << "Yes\n";
//            return;
//        } else {
//            std::cout << "No\n";
//            return;
//        }
//    }
    std::cout << "No\n";
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}