#define LOCAL
//P1463 [POI2001] [HAOI2007] 反素数
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
int prime[11] = {2,3,5,7,11,13,17,19,23,29,31};
int N;
int power[11]{0};
long long minNum = -1;
long long nNum = -1;
void dfs(long long a,int m,long long n) {
    //a是目前的和，m是上一层的质数编号，n是因数数量
    if(m>=1) {
        if(power[m]>power[m-1]) return;
    }
    if(a>N) {
        if(n>nNum) {
            nNum = n;
            minNum = a/prime[m];
            return;
        }
        else if(n == nNum) {
            if(minNum > a/prime[m]) {
                minNum = a/prime[m];
            }
            return;
        }
        return;
    }

    for(int i = m;i<11;i++) {
        if(i>=1) {
            if(power[i]>power[i-1]) {
                return;
            }
        }
        long long mm = n/(power[i]+1);
        power[i]++;
        mm = mm*(power[i]+1);
        dfs(a*prime[i],i,mm);
        power[i]--;
    }
}
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif

    cin >> N;
    dfs(1,0,1);
    cout << minNum << endl;

#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}