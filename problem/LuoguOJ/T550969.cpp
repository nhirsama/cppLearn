
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
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y =0,z=0;
        cin>>x;
        for(int j=0;j<x;j++){
            int m;
            cin>>m;
            if(m==1){
                y++;
            }
            else z++;
        }
        double dirt = (double)(x-y)/(double)x;
        cout<<dirt<<endl;
    }

#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}