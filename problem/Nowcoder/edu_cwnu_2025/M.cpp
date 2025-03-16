#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
int arr[N][N];
int main(){
    int n,m;
    cin>>n>>m;
    long long csum = 0,ysum = 0;
    for(int i = 1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        arr[x][y] = z;
        csum+=z;
    }
    int x = 0,y = 0;
    bool deied = true;
    for(int i = 1;i<=n;i++){
        char op;
        cin>>op;
        
        if(op == 'M'){
            cin>>x>>y;
            if(deied){
                csum-=arr[x][y];
                ysum+=arr[x][y];
                arr[x][y] = 0;
            }
        }
        if(op == 'D'){
            deied = false;
            csum+=ysum/2;
            arr[x][y]+=ysum/2;
            ysum = 0;
        }
        if(op == 'R'){
            deied = true;
        }
    }
    cout<<ysum<<' '<<csum<<endl;
}