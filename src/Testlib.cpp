#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL C(int a, int b) {
    LL res = 1;
    for (int i = 1; i <= b; i ++ ) res = res * (a - i + 1) / i;

    return res;
}

int main(){
    string s;
    while (cin>>s) {
        int n = 0;
        for(char c:s){
            if('a'<=c && c<='z')n++;
        }
        long long ans = 0;
        for (int i = 0;i<=n;i++) {
            ans+=C(n,i);
        }
        cout<<ans<<endl;
    }
}