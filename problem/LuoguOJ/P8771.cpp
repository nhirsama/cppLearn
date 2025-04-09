//P8771 [蓝桥杯 2022 省 B] 填空问题
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

void B() {
    for (i32 i = 0; i <= 9999; i++) {
        if (i / 10 == 12) {
            std::cout << i << endl;
        } else if (i / 10 == 123) {
            std::cout << i << endl;
        } else if (i % 1000 == 12 || i % 1000 == 123) {
            std::cout << i << endl;
        }
    }
}

void nhir() {
    //std::cout<<2*9*9*9+2*9+2<<endl;
    std::string ans[] = {
        "1478", // 双引号中替换为 A 题的答案
        "14", // 双引号中替换为 B 题的答案
    };
    char T;
    std::cin >> T;
    std::cout << ans[T - 'A'] << endl;
}

signed main() {
    IOS;
    i32 T = 1;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
        std::cin >> T;
    }
    //B();
    while (T--) nhir();
    return 0;
}
