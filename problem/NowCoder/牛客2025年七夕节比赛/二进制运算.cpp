//  二进制运算
//  19:15
#include <bits/stdc++.h>

using int64 = int64_t;
using i32 = int64_t;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
constexpr char enld = '\n';
constexpr int64 inf_i64 = 0x3f3f3f3f3f3f3f3f;
constexpr std::string OJ_NAME{"NowCoder"};

void nhir() {
    int a, b;
    char op;
    scanf("%b\n", &a);
    scanf("%b\n", &b);
    scanf("%c\n", &op);
    if (op == '+') {
        std::cout << a + b << endl;
    } else if (op == '-') {
        std::cout << a - b << enld;
    } else if (op == '*') {
        std::cout << a * b << enld;
    } else {
        std::cout << a / b << enld;
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    if (OJ_NAME != "AtCoder")
        //    std::cin >> T;
            while (T--) nhir();
    return 0;
}
