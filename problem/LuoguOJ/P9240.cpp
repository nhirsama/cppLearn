//P9240 [蓝桥杯 2023 省 B] 冶炼金属
#include <bits/stdc++.h>
using namespace std;

int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,ansmax = 0x3f3f3f3f,ansmin = 0;
    cin>>n;
    for (int i = 1;i<=n;i++) {
        long long a,b;
        cin>>a>>b;
        ansmax = min(ansmax,a/b);
        ansmin = max(ansmin,a/(b+1)+1);
    }
    cout<<ansmin<<' '<<ansmax;
    return 0;
}
