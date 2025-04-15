//  D. Tung Tung Sahur
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
    std::string s,p;
    std::cin>>p>>s;
    i32 its = 0,itp = 0,cnts = 0,cntp = 0;
    while(its<s.size() || itp<s.size()){
        if(s[its]!=p[itp]){
            std::cout<<"NO\n";
            return ;
        }
        i32 tits = its,titp = itp;
        while(tits<s.size() && s[its] == s[tits++]) cnts++;
        while(titp<p.size() && p[itp] == p[titp++]) cntp++;
        its = tits;
        itp = titp;
        if(cnts>=cntp && cntp*2>=cnts) cntp = cnts = 0;
        else {
            std::cout<<"NO\n";
            return ;
        }
    }
    std::cout<<"YES\n";
}

signed main() {
    IOS;
    i32 T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}