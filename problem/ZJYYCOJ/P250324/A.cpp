//模板
#include <bits/stdc++.h>
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef std::pair<i32, i32> pii;
constexpr int N = 1e5 + 10;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all1(x) (x).begin() + 1, (x).end()
#define int long long

void nhir(i32 n) {
    std::vector<i32> v(n + 1);
    for (i32 i = 1; i <= n; i++) {
        std::cin >> v[i];
    }
    i32 i = 1, j = n;
    for (i32 cnt = 1; cnt <= j && i < j; cnt++) {
        if (i < j && v[i] <= v[i + 1] && v[i] <= v[j]) {
            i++;
        }
        if (j > i && v[j - 1] <= v[j] && v[i] <= v[j]) {
            j--;
        }
    }
    std::cout << j - i << endl;
}

signed main() {
    IOS;
    i32 T = 1;
    i32 n;
    while (std::cin >> n) nhir(n);
    return 0;
}
