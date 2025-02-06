//P7859 [COCI 2015/2016 #2] GEPPETTO
//状压dp
#include <bits/stdc++.h>
using namespace std;
const int N = 25,M =  405;
int n,m,ans;
pair<int,int> arr[M];
int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        arr[i].first = a;
        arr[i].second = b;
    }
    for (int i = 0; i < 1<<n; i++) {
        bool flag = true;
        for(int j = 0; j<m;j++){
            if((i>>arr[j].first-1 & 1) & (i>>arr[j].second-1 & 1)){
                flag = false;
                break;
            }
        }
        if(flag){
            ans++;
        }
    }
    cout << ans;
    return 0;
}
