//A. 合法括号的数量
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define x first
#define y second
#define endl '\n'
#define space << ' '
typedef pair<int, int> pii;
int n;
long long ans = 0;
void dfs(int a,int b){
    if (a == n && b == n) {
        ans++;
        return;
    }
    if (a < n) dfs(a+1,b);
    if (b < n && b<a) dfs(a,b+1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin>>n){
        ans = 0;
        dfs(0,0);
        cout<<ans<<endl;
    }
    return 0;
}
