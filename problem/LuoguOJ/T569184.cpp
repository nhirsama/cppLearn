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
signed main() {
    std::string s;
    getline(std::cin,s);
    std::vector<std::string> arr;
    std::string t;
    while(getline(std::cin,t)){
        arr.push_back(t);
    }
    i32 ans = 0;
    for(i32 i = arr.size()-1;~i;i--){
        if(arr[i] == "1") ans++;
        else if (ans && arr[i] == "0"){
            break;
        }
    }
    std::cout<<ans<<endl;
    return 0;
}
