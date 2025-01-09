#define LOCAL
//P1939 矩阵加速（数列）
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
struct matrix{
    long long int A[4][4];
    matrix(){
        memset(A,0,sizeof(A));
    }
    matrix operator * (const matrix &b) const{
        matrix res;
        for(int i=1;i<4;i++){
            for(int j=1;j<4;j++){
                for(int k=1;k<4;k++){
                    res.A[i][j]+=A[i][k]*b.A[k][j]%mod;
                    res.A[i][j]%=mod;
                }
            }
        }
        return res;
    }
};
void quick_pow(matrix & ans,matrix & base,long long int n){
    while(n){
        if(n&1){
            ans=ans*base;
        }
        base=base*base;
        n>>=1;
    }
}
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    int T;
    cin>>T;
    pair<int ,int>p[105];
    for(int i=1;i<=T;i++){
        cin>>p[i].first;
        p[i].second=i;
    }
    sort(p+1,p+T+1);
    int ans[105];


    for(int i=1;i<=T;i++){
        if(p[i].first <= 3){
            ans[p[i].second]=1;
            continue;
        }
        matrix base,ansMat;
        base.A[1][1] = base.A[1][2] = base.A[2][3] = base.A[3][1]= 1;
        ansMat.A[1][1] = ansMat.A[1][2] = ansMat.A[1][3] = 1;
        quick_pow(ansMat,base,p[i].first-3);
        ans[p[i].second]=ansMat.A[1][1]%mod;
    }
    for(int i=1;i<=T;i++){
        cout<<ans[i]<<endl;
    }
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}