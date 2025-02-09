#include <bits/stdc++.h>
using namespace std;
void Func(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1),b(m);

    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<m;i++){
        scanf("%d",&b[i]);
    }
    sort(b.begin(),b.end());
    a[0] = -0x3f3f3f3f;
    for(int i=1;i<=n;i++) {
        int min1 = 0x3f3f3f3f;
        int find = lower_bound(b.begin(),b.end(),a[i]+a[i-1])-b.begin();
        if (find != m) {
            if (b[find]-a[i]>=a[i-1] && a[i]>=a[i-1]) {
                min1 = min(min(a[i],min1),b[find]-a[i]);
            }
            else if (b[find]-a[i]>=a[i-1]) min1 = min(min1,b[find]-a[i]);
        }
        // for(int j=1;j<=m;j++) {
        //     if (b[j]-a[i]>=a[i-1] && a[i]>=a[i-1]) {
        //         min1 = min(min(a[i],min1),b[j]-a[i]);
        //     }
        //     else if (b[j]-a[i]>=a[i-1]) min1 = min(min1,b[j]-a[i]);
        // }
        if (min1 != 0x3f3f3f3f)a[i] = min1;
    }
    for(int i=1;i<n;i++){
        if(a[i+1]<a[i]) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
    return;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        Func();
    }
    return 0;
}
