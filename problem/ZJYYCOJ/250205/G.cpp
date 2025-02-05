#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int prime[N],cnt;
bool notPrime[N];
long long ans,n,yueNum[N];

int main(){
    cin>>n;
    notPrime[0]=notPrime[1]=true;
    for(int i=2;i<=n;i++){
        if(!notPrime[i]){
            prime[++cnt]=i;
        }
        for(int j=1;i*prime[j]<=n;j++){
            notPrime[i*prime[j]]=true;
            if(i%prime[j]==0){
                break;
            }
        }
    }
    yueNum[1]=1;
    for(int i=2;i<=n;i++) {
        int num = 1,aa = i;
        if(!notPrime[aa]) {
            yueNum[aa] = 2;
            continue;
        }
        for(int j=1;j<=cnt && aa;j++) {
            int bb = 0;
            bool flag = true;
            while(aa%prime[j]==0) {
                aa = aa/prime[j];
                bb++;
                flag = false;
            }
            if(!flag) {
                num = yueNum[i/prime[j]] + yueNum[aa];
                break;
            }
            num*=bb+1;
        }
        yueNum[i]=num;
    }
        for(int i=1;i<n;i++) {
            ans+=yueNum[i]*yueNum[n-i];
        }
    cout<<ans<<endl;
    return 0;
}