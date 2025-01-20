#include <bits/stdc++.h>
using namespace std;
int find(int arr[], int n){
    return arr[n] == n ? n : arr[n] = find(arr, arr[n]);
}
void Func(){
    int n,m1,m2;
    cin>>n>>m1>>m2;
    int Fb[n+1],cntF = n,cntG = n,Gb[n+1];
    for(int i=1;i<=n;i++){
        Fb[i]=i;Gb[i]=i;
    }
    vector<int> F[n+1],G[n+1];
    for(int i=1;i<=m1;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        F[x].push_back(y);
        F[y].push_back(x);
        int a = find(Fb,x);
        int b = find(Fb,y);
        if(a!=b){
            cntF--;
            Fb[a]=b;
        }
    }
    for(int i=1;i<=m2;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
        int a = find(Gb,x);
        int b = find(Gb,y);
        if(a!=b){
            cntG--;
            Gb[a]=b;
        }
    }
    cout << abs(cntF-cntG) << endl;
}
int main() {
    int T;
    cin>>T;

    while(T--){
        Func();
    }
    return 0;
}