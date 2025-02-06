//P3216 [HNOI2011] 数学作业
#include <bits/stdc++.h>
using namespace std;
int mod = 1000000007;
struct matrix {
    long long i, j;
    vector<vector<long long> > mat;

    matrix(long long a, long long b) {
        this->i = a;
        this->j = b;
        this->mat = vector(a, vector<long long>(b, 0));
    }

    matrix operator*(const matrix &mata) const {
        matrix res(i, mata.j);
        for (int a = 0; a < i; a++) {
            for (int b = 0; b < mata.j; b++) {
                for (int c = 0; c < j; c++) {
                    res.mat[a][b] += this->mat[a][c] * mata.mat[c][b] % mod;
                    res.mat[a][b] %= mod;
                }
            }
        }
        return res;
    }
}ans(1,3),base(3,3);

matrix mat_pow(matrix a, long long b) {
    if (b == 0)return ans;
    matrix res = ans;
    while (b) {
        if (b & 1) {
            res = res * a;
        }
        b = b >> 1;
        a = a * a;
    }
    return res;
}
// struct matrix{
//     long long int mat[5][5];
//     matrix(){
//         memset(mat,0,sizeof mat);
//     }
//     matrix operator*(const matrix& b) const{
//         matrix ans;
//         for(int i=0;i<5;i++){
//             for(int j=0;j<5;j++){
//                 for(int k=0;k<5;k++){
//                     ans.mat[i][j] += mat[i][k] * b.mat[k][j]%mod;
//                     ans.mat[i][j] %= mod;
//                 }
//             }
//         }
//         return ans;
//     }
// }ans,base;
// matrix qpow(matrix a,matrix b ,long long k){
//     while(k){
//         if(k&1){
//             a = a*b;
//         }
//         b = b*b;
//         k>>=1;
//     }
//     return a;
// }
int main() {
    if (getenv("ONLINE_JUDGE") == nullptr) {
        freopen("Testlib.in", "r", stdin);
        freopen("Code.out", "w", stdout);
    }
    long long n;
    cin>>n>>mod;
    //n%=mod;
    //ans.mat[0][0] = 1;
    ans.mat[0][1] = 1;
    ans.mat[0][2] = 1;
    base.mat[0][0] = 10;
    base.mat[1][0] = 1;
    base.mat[1][1] = 1;
    base.mat[2][1] = 1;
    base.mat[2][2] = 1;
    int pown = 1;
    for (unsigned long long k = 10;; k *= 10) {
        base.mat[0][0] = k % mod;
        if (n < k) {
            ans = mat_pow(base, n - k / 10 + 1);
            break;
        }
        ans = mat_pow(base, k - k / 10);
    }
    // while(n>0){
    //     if(pown == 1){
    //         ans = mat_pow(base,min(9*1ll,n));
    //     }
    //     else {
    //         base.mat[0][0]*=10;
    //         ans = mat_pow(base,min((long long)pow(10,pown-1)*9,n));
    //     }
    //     n-=((long long)pow(10,pown-1))*9;
    //     pown++;
    // }
    cout<<ans.mat[0][0]<<endl;
    return 0;
}
