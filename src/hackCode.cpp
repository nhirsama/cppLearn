//模板
#include <bits/stdc++.h>
using i128 = __int128;
using i64 = long long int;
using LL = long long int;
using i32 = int;
typedef std::pair<i32, i32> pii;
constexpr int N = 1e5 + 10;
using namespace std;
constexpr int mod = 1e9+7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void nhir() {
    int n;
    cin >> n;
    vector<LL>arr(n + 1);
    map<LL , LL>mp;
    for(int i = 1 ; i <= n ; i ++){
        cin >> arr[i];
    }

    LL res = 0;

    for(int i = 1 ; i <= n ; i ++){
        LL x = 0;
        cin >> x;
        while(!mp[x]){
            mp[x] = 1;
            res ++;
            x = arr[x];
        }

        cout<<res<<" ";
    }
    cout<<"\n";
}

signed main() {
    IOS;
    const clock_t beginTime = clock();
    i32 T = 1;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    std::cin>>T;
    while (T--) nhir();
    const clock_t endTime = clock();
    std::cout << "本程序运行时间为" << static_cast<double>(endTime - beginTime) << "毫秒" << endl;
    return 0;
}
