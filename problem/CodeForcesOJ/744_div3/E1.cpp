//E1
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
    i32 n;
    std::cin>>n;
    std::vector<i32>v(n);
    for(i32 &i:v)std::cin>>i;
    std::deque<i32> q;
    for(i32 i = 0;i<n;i++){
        if(q.size() == 0){
            q.push_back(v[i]);
        }
        else {
            if(v[i]<=q.front()){
                q.push_front(v[i]);
            }
            else{
                q.push_back(v[i]);
            }
        }
    }
    while(q.size()){
        std::cout<<q.front()<< ' ';
        q.pop_front();
    }
    std::cout<<endl;
}

signed main() {
    IOS;
    i32 T = 1;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
    }
    std::cin>>T;
    while (T--) nhir();
    return 0;
}
