//A
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
    std::string s;
    i32 a, b, c;
    std::cin>>s;
    a = std::count(all(s), 'A');
    b = std::count(all(s), 'B');
    c = std::count(all(s), 'C');
    if (b == a + c) {
        std::cout << "YES" << endl;
    } else {
        std::cout << "NO" << endl;
    }
}

signed main() {
    IOS;
    i32 T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
