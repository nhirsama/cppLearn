//F
#include <bits/stdc++.h>
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef std::pair<i32, i32> pii;
constexpr int N = 1e5 + 10;
constexpr int mod = 1e9+7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void nhir() {
    std::string s;
    std::cin>>s;
    bool flag = false;
    for(auto c:s) if(c == '1') flag = true;
    for(auto c:s) if(c != '2' || flag == false) std::cout<<c;
}

signed main() {
    IOS;
    i32 T = 1;
    while (T--) nhir();
    return 0;
}
