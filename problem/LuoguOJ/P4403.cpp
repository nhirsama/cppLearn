#define LOCAL
//P4403 [BJWC2008] 秦腾与教学评估
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
struct node {
    int s,e,d;
}arr[200000];
bool sortCmp(node &a,node &b) {
    return a.e<b.e;
}
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--) {
        int n;
        scanf("%d", &n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d",&arr[i].s,&arr[i].e,&arr[i].d);
            for (int j = arr[i].s; j <= arr[i].e; j+=arr[i].d) {
                ans ^= j;
            }
        }
        //if(ans == 0) cout << "There's no weakness." << endl;
        //双倍经验
        if(ans == 0) cout << "Poor QIN Teng:(" << endl;
        //以下为暴力遍历，会TLE
        else {
            int num = 0;
            sort(arr, arr + n, sortCmp);
            int l = 0 ,r = n;
            while(l<r) {
                int mid = l+r>>1;
                if(arr[mid].e<ans) l = mid+1;
                else r = mid;
            }
            for (int i = l; i<n || ans<arr[i].e;i++) {
                for (int j = arr[i].s; j<=arr[i].e; j+=arr[i].d) {
                    if(ans == j) {
                        num++;
                        break;
                    }
                }
            }
            cout << ans << ' ' << num << endl;
        }
        end1:
    }
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}