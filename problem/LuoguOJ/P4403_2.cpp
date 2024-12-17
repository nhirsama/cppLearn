#define LOCAL
//P4403 [BJWC2008] 秦腾与教学评估
//记得把文件重定向注释掉
//TLE,为非正确时间复杂度算法
#include <bits/stdc++.h>
using namespace std;
struct node {
    int s,e,d;
}arr[200005];
int Func(int m,int n) {
    int a = 0;
    for (int i = 0; i < n; i++) {
        if(arr[i].s<=m) a+=(min(m,arr[i].e)-arr[i].s)/arr[i].d+1;
    }
    return a;
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
        int max = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d",&arr[i].s,&arr[i].e,&arr[i].d);
            if(arr[i].e>max) max = arr[i].e;
        }
        //if(ans == 0) cout << "There's no weakness." << endl;
        //双倍经验
        if(Func(max,n)%2 == 0) cout << "Poor QIN Teng:(" << endl;
        //以下为暴力遍历，会TLE
        else {
            int num = 0;
            int l = 0 ,r = max;
            while (l < r) {
                int mid = 1ll*l+1ll*r>>1;
                if(Func(mid,n)%2) r = mid;
                else l = mid+1;
            }
            ans = l;
            for (int i = 0; i < n; i++) {
                if(arr[i].s<=ans && arr[i].e>=ans) {
                    if((ans-arr[i].s)%arr[i].d == 0) num++;
                }
            }
            // sort(arr,arr+n,sortCmp);
            // l=0,r=n;
            // while(l<r) {
            //     int mid = l+r>>1;
            //     if(arr[mid].e<ans) l = mid+1;
            //     else r = mid;
            // }
            // for (int i = l; i<n && ans<=arr[i].e;i++) {
            //     if(arr[i].s>ans) continue;
            //     if(arr[i].d == 0) {
            //         if(arr[i].s == ans) num++;
            //     }
            //     else if((ans-arr[i].s)%arr[i].d == 0) num++;
            // }
            cout << ans << ' ' << num << endl;
        }
    }
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}