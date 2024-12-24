#define LOCAL
//P1414 又是毕业季II
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;

int n,a[10005],b[1000005];
int main() {
#ifdef LOCAL
    freopen("inAndoutFile/P1414_7.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        for(int j = 1; j <= sqrt(a[i]); j++) {
            if(a[i]%j == 0) {
                b[j]++;
                if (a[i]/j != j) b[a[i]/j]++;
            }
        }
    }
    int t = 1000000;
    for(int i = 1; i <= n; i++) {
        for (int j = t; j ;j--) {
            if (b[j]>=i) {
                cout << j << '\n';
                t = j;
                break;
            }
        }
    }
    cout << endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}