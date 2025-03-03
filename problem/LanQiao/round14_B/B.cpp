#include <bits/stdc++.h>
using namespace std;
int main() {
    // int n = 23333333;
    // double eee = 0.01;
    // double ans = 11625907.5798;
    // for (double i = 1;i<=n/2;i++) {
    //     double aaa = -(i*i/n)*log2(i/n)-((n-i)*(n-i)/n)*log2((n-i)/n);
    //     if (abs(ans-aaa)<=eee) cout<<(int)i<<' '<<(int)n-i<<endl;
    // }
    double i = 11027421;
    int n = 23333333;
    double aaa = -(i*i/n)*log2(i/n)-((n-i)*(n-i)/n)*log2((n-i)/n);
    cout<<(int)(n-i)<<endl;
    printf("%.4f",aaa);
    return 0;
}
