/*
//警钟长鸣，欧拉质数筛喜提RE
#define LOCAL
//B3715 分解质因子 2
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
bool isPrime[1000010];
int prime[1000005];
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    int cnt = 0;
    int T;
    scanf("%d", &T);
    long long N[15];
    long long Max = 0;
    for (int i = 0; i < T; i++) {
        scanf("%lld", &N[i]);
        if (N[i]>Max) Max = N[i];
    }
    Max = (long long)sqrt(Max);
    isPrime[0] = isPrime[1] = true;
    for (int i = 2; i < Max; i++) {
        if (!isPrime[i]) {
            prime[++cnt] = i;
        }
        for (int j = 1; j <= cnt && i*prime[j] <= Max; j++) {
            isPrime[i*prime[j]] = true;
            if (i%prime[j] == 0)break;
        }
    }
    for (int i = 0; i < T; i++) {
        int n = N[i];
        for (int j = 1; j<=cnt && n > 1;j++) {
            if (n%prime[j] == 0) {
                cout << prime[j] << ' ';
                n /= prime[j];
                j = 0;
            }
        }
        cout << endl;
    }
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
*/

#define LOCAL
//模板
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    int n;
    cin >> n;
    while (n--) {
        long long a;
        cin >> a;
        long long b = sqrt(a)*1ll+1;
        for (int i = 2; i <= b; i++) {
            while (a % i == 0) {
                a /= i;
                cout << i << " ";
            }
        }
        if (a != 1) {
            cout << a;
        }
        cout << endl;
    }

#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}