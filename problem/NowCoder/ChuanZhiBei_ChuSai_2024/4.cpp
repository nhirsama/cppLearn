#include <iostream>
using namespace std;
string str;
int st[256];
int stNum = 0;
int main() {
    int n,k;
    cin>>n>>k;
    cin>>str;
    int i =0,j = 0;
    int ans = 0;
    while(i<=j&&j<str.size()){
        if(st[str[j]]) {
            st[str[j]]++;
        }
        else{
            stNum++;
            st[str[j]]++;
        }
        while(stNum>k) {
            st[str[i]]--;
            if(st[str[i]]==0) {
                stNum--;
            }
            i++;
        }
        if(ans<j-i+1)ans = j-i+1;
        j++;
    }
    if(ans<j-i)ans = j-i;
    cout<<ans<<endl;
}
// 64 位输出请用 printf("%lld")