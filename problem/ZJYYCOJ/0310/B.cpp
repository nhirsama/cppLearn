//模板
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 15;
typedef long long int ll;
#define x first
#define y second
#define endl '\n'
#define space << ' '
typedef pair<int, int> pii;
int n,k;
long long ans = 0;
bool st[N];
void dfs(int a,int sum,int cnt){
    if(a == n && sum == k){
        ans++;
        return;
    }
    for(int i = cnt+1; i <= 9; i++){
        if(st[i]) continue;
        st[i] = true;
        dfs(a+1,sum+i,i);
        st[i] = false;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin >> n >> k) {
        ans = 0;
        dfs(0,0,0);
        if(ans == 0){
            cout<<"No list"<<endl;
        }
        else cout << ans << endl;
    }
    return 0;
}
