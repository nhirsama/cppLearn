//T573806 [语言月赛 202502] 本俗妙手不如举手
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 5e3+10;
typedef long long int ll;
#define x first
#define y second
typedef pair<int, int> pii;
int arr[N];
int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    int n,k;
    cin>>n>>k;
    ll h = 0,b = 0;
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
        h+=arr[i];
        b+=99-arr[i];
    }

    return 0;
}
