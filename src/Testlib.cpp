#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
signed main() {
    ios::sync_with_stdio(false);
    while (cin >> n) {
        int son = n, mother = 1;
        for (int i = 2; i <= n; i++) {
            son = son * i + n * mother;
            mother *= i;
            int g = gcd(son, mother);
            son /= g;
            mother /= g;
        }
        //输出部分
        if (son % mother == 0) {
            printf("%lld\n", son / mother);
            continue;
        } else {
            int c = log10(son / mother) + 1;
            int c2 = log10(mother) + 1;
            for (int i = 1; i <= c + 1; i++)printf(" ");
            printf("%lld\n", son % mother);
            printf("%lld ", son / mother);
            for (int i = 1; i <= c2; i++)printf("-");
            puts("");
            for (int i = 1; i <= c + 1; i++)printf(" ");
            printf("%lld\n", mother);
        }
    }
    return 0;
}
