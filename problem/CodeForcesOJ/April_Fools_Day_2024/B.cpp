//模板
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
    for(i32 i = 0;i<s.size()-1;i++){
        if(s[i] == 'i' && s[i+1] == 't'){
            std::cout<<"Yes"<<endl;
            return;
        }
    }
    std::cout<<"No"<<endl;
}

signed main() {
    IOS;
    i32 T = 1;
    std::cin>>T;
    while (T--) nhir();
    return 0;
}
