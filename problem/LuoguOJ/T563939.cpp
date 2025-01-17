#define LOCAL
//T563939 [202501F] 知识竞赛
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
int n,m;
int ans,arr[55][55];
vector<int> win;
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&arr[i][j]);
            arr[n][j]+=arr[i][j];
        }
    }
    for(int i=0;i<m;i++){
        if(arr[n][i]>=arr[n][ans]) ans=i;
    }
    int ians = 0;
    for(int i=0;i<n;i++){
        if(arr[i][ans]>arr[ians][ans]) {
            ians=i;
            win = vector<int>();
            win.push_back(arr[i][ans]);
        }
        else if(arr[i][ans]== arr[ians][ans]) win.push_back(arr[i][ans]);
    }
    cout << arr[ians][ans] << ' '<< win.size() << endl;
    //for(auto i : win) printf("%d ",i);
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}