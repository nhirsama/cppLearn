//T573803 [语言月赛 202502] 地铁环线
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5+10;
typedef long long int ll;
#define x first
#define y second
typedef pair<int, int> pii;
int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    ll n,x,y;
    cin >> n>>x>>y;
    bool flag = x<y;
    ll ans1,ans2;
    if (flag) {
        ans1 = y-x;
        ans2 = x-y+n;
    }
    else {
        ans1 = y-x+n;
        ans2 = x-y;
    }
    if(ans1<ans2) puts("Clockwise Loop");
    else if(ans1>ans2) puts("Counter-clockwise Loop");
    else puts("\"Wonderful\"");
    return 0;
}
