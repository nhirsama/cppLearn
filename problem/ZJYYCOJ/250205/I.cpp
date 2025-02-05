#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int pi[N],qi[N],ci[N],a,b,c,x,y;
long long ans = 0;
bool sortCmp(int a, int b) {
    return a > b;
}
int main(){
    cin>>x>>y>>a>>b>>c;
    for(int i=1;i<=a;i++){
        scanf("%d",&pi[i]);
    }
    for(int i=1;i<=b;i++){
        scanf("%d",&qi[i]);
    }
    for(int i=1;i<=c;i++){
        scanf("%d",&ci[i]);
    }
    sort(pi+1,pi+a+1,sortCmp);
    sort(qi+1,qi+b+1,sortCmp);
    sort(ci+1,ci+c+1,sortCmp);
    int nowx=1,nowy=1,nowz = 1;
    for(int i=1;i<=x+y;i++){
        if (nowx>x) pi[nowx] = 0;
        if (nowy>y) qi[nowy] = 0;
        int maxa = max(pi[nowx],max(qi[nowy],ci[nowz]));
        if(maxa==pi[nowx]){
            ans+=pi[nowx++];
        }
        else if(maxa==qi[nowy]){
            ans+=qi[nowy++];
        }
        else if(maxa==ci[nowz]){
            ans+=ci[nowz++];
        }
    }
    cout<<ans<<endl;
    return 0;
}