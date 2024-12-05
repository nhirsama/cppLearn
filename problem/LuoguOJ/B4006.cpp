//B4006 [GESP202406 四级] 宝箱
//记得把文件读写流和define注释掉
#include <bits/stdc++.h>
using namespace std;
int arr[1005];
int main() {
#define cin fin
//#define cout fout
    ifstream fin("Testlib.in");
    ofstream fout("Code.out");
    int n,k;
    cin>>n>>k;
    for(int i =1;i<=n;i++){
      cin>>arr[i];
    }
    int ans = 0;
    sort(arr+1,arr+n+1);
    int sum = 0;
    for(int i=1,j = 1;i<=n;i++){
        sum += arr[i];
        while(arr[i]-arr[j]>k) {
            sum -= arr[j];
            j++;
        }
        ans = max(ans,sum);
    }
    cout<<ans<<endl;
    return 0;
}