#define LOCAL
//P4552 [Poetize6] IncDec Sequence
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
long long arr[100005];
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        long long temp;
        scanf("%lld", &temp);
        arr[i] = temp-sum;
        sum = temp;
    }
    long long nNum = 0,pNum = 0;
    for (int i = 2; i <= n; i++) {
        if (arr[i]>0) {
            pNum += arr[i];
        }
        else {
            nNum += arr[i];
        }
    }
    nNum = -nNum;
    cout << max(nNum,pNum) << endl;
    cout << abs(nNum-pNum)+1 << endl;


#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}