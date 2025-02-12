#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
typedef long long int ll;
#define first x;
#define second y;
double ans,time11[N],ai[N],bi[N];
ll n;
int main() {
    cin>>n;
    for(int i=1;i<=n;i++)cin>>ai[i]>>bi[i];
    for(int i=1;i<=n;i++)time11[i]=ai[i]/bi[i],ans+=time11[i];
    ans/=2;
    double aaa = 0;
    double len = 0;
    for(int i=1;i<=n;i++){
        if(aaa+time11[i]>=ans){
          len=(ans-aaa)*bi[i];
          for(int j=1;j<i;j++){
              len+=ai[j];
          }
       break;
       }
        aaa+=time11[i];
    }
    printf("%.13lf\n",len);
    return 0;
}
