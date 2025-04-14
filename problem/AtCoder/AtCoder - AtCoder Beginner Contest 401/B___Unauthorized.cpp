//  B - Unauthorized
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
    std::cin>>n;
    bool cooki = false;
    int cnt = 0;
    while(n--){
        std::string s;
        std::cin>>s;
        if(s == "login") cooki = true;
        else if(s == "logout") cooki = false;
        else if(s == "public"){}
        else if(s == "private" && cooki == false) cnt++;
        else {};
    }
    std::cout<<cnt<<endl;
}

signed main() {
    IOS;
    i32 T = 1;
    while (T--) nhir();
    return 0;
}