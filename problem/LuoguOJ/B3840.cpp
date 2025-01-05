//B3840 [GESP202306 二级] 找素数
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
bool notPrime[N];
int prime[N],idx = 0,ans = 0,n,m;
void getPrime(){
    notPrime[0] = notPrime[1] = true;
    for(int i = 2; i <= m;i++){
        if(!notPrime[i]){
            prime[idx++] = i;
            if(n<=i && i<=m) ans++;
        }
        for(int j = 0; j < idx && prime[j]*i <= m; j++){
            notPrime[prime[j]*i] = true;
            if(i%prime[j] == 0){
                break;
            }
        }
    }
}
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    cin >> n >> m;
    getPrime();
    cout << ans << endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}