#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int arr[105];
    cin>>n;
    int sum = 0;
    vector<int>v[105];
    for(int i = 1;i<=n;i++){
        cin>>arr[i];
        arr[i]*=10;
        sum+=arr[i];
    }
    int num = 1;
    int d = n;
    int st[105]{0};
    while(sum){
        if(d==1){
            int aaa = 0;
            for(int i = 1;i<=n;i++){
                if(arr[i]){
                    aaa = i;
                    break;
                }
            }
            while(arr[aaa]){
                v[aaa].push_back(++num);
                num++;
                arr[aaa]--;
                sum--;
            }
        }
        for(int i = 1;i<=n;i++){
            if (d == 1)continue;
            if(arr[i]){
                v[i].push_back(num++);
                arr[i]--;
                sum--;
            }
            else if(arr[i] == 0 && st[i] == 0) {
                d--;
                st[i] = 1;
            }
        }
    }
    for(int i = 1;i<=n;i++){
        cout<<'#'<<i<<'\n';
        int cnt = 0;
        for(int j = 0;j<v[i].size();j++){
            cout<<v[i][j]-(n == 1);
            cnt++;
            if (cnt == 10) {
                cout<<'\n';
                cnt = 0;
            }
            else if(j!=v[i].size()-1)cout<<' ';
            else cout<<'\n';
        }
    }
    return 0;
}