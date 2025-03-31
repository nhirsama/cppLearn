//B
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
    i32 n;
    std::cin >> n;
    std::vector<i32> arr(n+1);
    for (i32 i = 1;i<=n;i++) {
        std::cin>>arr[i];
    }
    std::vector<pii> ans;
    for (i32 i = 1;i<n-1;i++) {
        i32 p = std::min_element(arr.begin()+i,arr.end())-arr.begin();
        ans.push_back({i,p});
        if (p> i) {
            ans.push_back({i, p});
            for (int j = p; j > i; j--)
                arr[j] = arr[j - 1];
        }
    }
    std::cout<<ans.size()<<endl;
    for (auto [x,y]:ans) {
        std::cout<<x<< ' '<<y<< ' '<<y-x<<endl;
    }
    // std::sort(1+all(arr));
    // i32 t = 0;
    // std::vector ans(0, std::vector<i32>(3));
    // for (i32 i = 1;i<n;i++) {
    //     t = (arr[i].second-i-t)%n;
    //     if (!t) continue;
    //     ans.push_back({i,n,t});
    //     arr[i].second;
    // }
    // std::cout << ans.size() << endl;
    // for (auto i: ans) {
    //     for (i32 j = 0; j < 3; j++) {
    //         std::cout << i[j] << ' ';
    //     }
    //     std::cout << endl;
    // }
}

signed main() {
    IOS;
    i32 T = 1;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
    }
    std::cin >> T;
    while (T--) nhir();
    return 0;
}
