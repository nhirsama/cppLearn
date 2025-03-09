#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int n,q;
    cin>>n>>q;
    vector<int> a(n+1),c(n+1),b(n+1);//b通过编号找宿舍，c通过宿舍找编号
    for(int i = 1;i<=n;i++){
        a[i] = i;
        b[i]=i;
        c[i]  =i;
    }
    while(q--){
        int op;
        cin>>op;
        if(op == 1){
            int aa,bb;
            cin>>aa>>bb;
            a[aa] = c[bb];//均为实际宿舍b的下标
        }
        if(op == 2){
            int aa,bb;
            cin>>aa>>bb;
            swap(b[c[aa]],b[c[bb]]);
            swap(c[aa],c[bb]);
        }
        if(op == 3){
            int aa;
            cin>>aa;
            cout<<b[a[aa]]<<endl;
        }
    }
    return 0;
}