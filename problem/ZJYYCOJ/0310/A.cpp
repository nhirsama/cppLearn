#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
long long ans = 0;
LL C(int a, int b) {
    if (b == 0) return 1;
    LL res = 1;
    for (int i = 1; i <= b; i ++ ) res = res * (a - i + 1) / i;
    return res;
}

int main(){
    string s;
    while (cin>>s) {
        int n = 0;
        for(char c:s){
            if (('a'<=c && c<='z') || ('A'<=c && c<='Z'))n++;
        }
        ans = 0;
        for (int i = 0;i<=n;i++) {
            ans+=C(n,i);
        }
        cout<<ans<<endl;
    }
    return 0;
}