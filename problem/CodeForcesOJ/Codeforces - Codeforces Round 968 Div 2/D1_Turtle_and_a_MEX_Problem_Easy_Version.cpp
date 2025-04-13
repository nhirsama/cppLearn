//  D1. Turtle and a MEX Problem (Easy Version)
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
    i64 n,m;
    std::cin>>n>>m;
    std::vector<i32> lmex,rmex;
    for(i32 i = 0;i<n;i++){
        i32 cnt = 0;
        i32 li;
        std::cin>>li;
//        std::vector<i32>a(li);
        std::vector<bool> st(li+2);
//        for(auto &j:a) std::cin>>j;
        for(i32 j = 0;j<li;j++){
            i32 it;
            std::cin>>it;
            if(it>=li+2) continue;
            st[it] = true;
        }
        for(i32 p = 0;p<li+2;p++){
            if(!st[p]){
                if(cnt == 0 ) lmex.push_back(p);
                else if(cnt == 1 ) rmex.push_back(p);
                cnt++;
                if(cnt>=2) break;
            }
        }
    }
    i64 maxl = *std::max_element(all(rmex));
    i64 ans = 0;
    if(maxl>=m) ans = (m+1)*maxl;
    else {
        ans = maxl*maxl+(m+maxl)*(m-maxl+1)/2;
    }
    std::cout<<ans<<endl;
//        std::sort(all(a));
//        i32 now = 0;
//        for(auto j:a){
//            if(j == now) now++;
//            else if( j<now) continue;
//            else {
//                if(cnt>=2) break;
//                cnt++;
//                lmex.push_back(now++);
//                if(now == j) now++;
//                else {
//                    if(cnt>=2) break;
//                    cnt++;
//                    lmex.push_back(now++);
//                    break;
//                }
//            }
//        }
//    }
//    std::sort(all(lmex));
//    i32 li = lmex.size();
//    std::vector<i32> rmex;
//    i32 cnt = 0;
//    std::vector<bool> st(li+2);
//    for(i32 j = 0;j<li;j++){
//        i32 it;
//        std::cin>>it;
//        if(it>=li+2) continue;
//        st[it] = true;
//    }
//    for(i32 p = 0;p<li+2;p++){
//        if(!st[p]){
//            rmex.push_back(p);
//            cnt++;
//            if(cnt>=2) break;
//        }
//    }
//    for(auto i:lmex) std::cout<<i<< ' ';
//    std::cout<<endl;
//    for(auto i:rmex) std::cout<<i<< ' ';
//    i64 ans = 0;
//    if(m<rmex[0]) ans = rmex[0]*m;
//    else {
//        ans = rmex[0]*(m-1)*rmex[1];
//    }
//    for(auto i:lmex) std::cout<<i<< ' ';
//    std::cout<<ans<<endl;
}

signed main() {
    IOS;
    i32 T = 1;
    std::cin >> T;
    while (T--) nhir();
    return 0;
}