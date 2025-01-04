#define LOCAL
//P1464 Function
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
int w[21][21][21];
int  Func(long long a,long long b,long long c){
    if (a<=0 || b<=0 || c<=0) return 1;
    else if (a > 20 || b > 20 || c > 20) return Func(20,20,20);
    else if (w[a][b][c]!= 0x3f3f3f3f) return w[a][b][c];
    else if (a < b && b < c) {
        w[a][b][c] = Func(a,b,c-1)+Func(a,b-1,c-1)-Func(a,b-1,c);
        return w[a][b][c];
    }
    else {
        w[a][b][c] = Func(a-1,b,c)+Func(a-1,b-1,c)+Func(a-1,b,c-1)-Func(a-1,b-1,c-1);
        return w[a][b][c];
    }
}
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    memset(w, 0x3f, sizeof w);
    long long a,b,c;
    while (scanf("%lld %lld %lld",&a,&b,&c)) {
        if (a == -1 && b == -1 && c == -1) break;
        printf("w(%lld, %lld, %lld) = %d\n",a,b,c,Func(a,b,c));
    }
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}