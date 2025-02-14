//T573807 [语言月赛 202502] 沿轴求和
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 17;
typedef long long int ll;
#define x first
#define y second
typedef pair<int, int> pii;
ll n,x;
int arr[N];
int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    cin>>n>>x;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
        if(i!=x) sum += arr[i];
    }
    for (int i = 0; i < sum; i++) {

    }
    return 0;
}
