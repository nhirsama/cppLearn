//  D - Logical Filling
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
    std::string s;
    i32 n,k;
    std::cin>>n>>k>>s;
    std::string tt = s;
    for(i32 i = 0;i<n;i++){
        if(i<n-1 && s[i] == 'o' && s[i+1] == '?') s[i+1] = '.';
        if(i>0 && s[i] == 'o' && s[i-1] == '?') s[i-1] = '.';
    }
    //std::cout<<s<<endl;
    i32 cnt = 0;
    std::string ts = s;
    for(i32 i = 0;i<n;i++){
        if(ts[i] == '?'){
            if(i>0 && ts[i-1] == 'o') continue;
            if(i<n-1 && ts[i+1] == 'o') continue;
            ts[i] = 'o';
            cnt++;
        }
    }
//    std::cout<<tt<<endl;
//    std::cout<<s<<endl;
//    std::cout<<ts<<endl;
    if(cnt+std::count(all(tt),'o')==k){
        i32 cntt = std::count(all(s),'?');
        if(cntt&1){
            std::cout<<ts<<endl;
        }
        else std::cout<<s<<endl;
    }
    else {
        std::cout<<tt<<endl;
        return;
    }
}

signed main() {
    IOS;
    i32 T = 1;
    while (T--) nhir();
    return 0;
}