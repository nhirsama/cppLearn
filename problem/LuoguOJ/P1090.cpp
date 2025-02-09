//P1090 [NOIP 2004 提高组] 合并果子
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
priority_queue<int> q;
int n;
int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        q.push(-x);
    }
    long long int ans=0;
    while(q.size()>1){
        int a = q.top();
        q.pop();
        a+=q.top();
        q.pop();
        q.push(a);
        ans+=a;
    }
    cout<<-ans<<endl;
    return 0;
}
