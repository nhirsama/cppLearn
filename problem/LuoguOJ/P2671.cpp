#define LOCAL
//P2671 [NOIP2015 普及组] 求和
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10,mod = 10007;

struct node {
    long long int i, num, color,iNum;
} arr[N];

struct node sum[N];
int n, m;

bool sortcmp(const struct node &a,const struct node &b) {
    if (a.color == b.color) {
        if ((a.i&1) == (b.i&1)) return a.i < b.i;
        return a.i&1;
    }
    return a.color < b.color;
}
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= n; i++) scanf("%lld", &arr[i].num);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &arr[i].color);
        arr[i].i = i;
        arr[i].iNum = i*arr[i].num%mod;
    }
    sort(arr + 1, arr + n + 1,sortcmp);
    for (int i = 1; i <= n; i++) {
        sum[i].i = arr[i].i+sum[i-1].i;
        sum[i].num = arr[i].num+sum[i-1].num;
        sum[i].iNum = arr[i].iNum+sum[i-1].iNum;
    }
    long long int ans = 0;
    for (int i = 1,j = 1; j <= n && i<=j;) {
        if ((arr[i].i&1)==(arr[j+1].i&1)&&(arr[i].color==arr[j+1].color)) {
            j++;
        }
        else {
            long long int temp = 0;
            //显然是下面的二重循环复杂度过高，导致TLE
            /*
            for (int k = i; k <= j; k++) {
                for (int l = k+1; l <= j; l++) {
                    temp += arr[k].i*arr[l].num+arr[k].num*arr[l].i;
                    temp %= mod;
                }
            }
            */
            for (int k = i; k < j; k++) {
                temp += arr[k].i*(sum[j].num-sum[k].num);
                temp += arr[k].num*(sum[j].i-sum[k].i);
                temp %= mod;
            }
            ans += (sum[j].iNum-sum[i-1].iNum)*(j-i)+temp;
            ans %= mod;
            i = j+1;
            j = i;
        }
    }
    cout << ans << endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
