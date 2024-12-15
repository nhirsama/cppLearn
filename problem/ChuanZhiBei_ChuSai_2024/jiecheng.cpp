#include <iostream>
using namespace std;
unsigned long long jiecheng(int n){
    if(n == 0) return 1;
    unsigned long long ans = 1;
    for(int i = 1;i<=n;i++){
        ans*=i;
    }
    cout<<ans<<endl;
    return ans;
}
int main(){
  cout<<jiecheng(4)*jiecheng(4)<<endl;
}