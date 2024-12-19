#include <bits/stdc++.h>
using namespace std;
vector<char> primes;
vector<char> mul(vector<char> &a,vector<char> &b) {
    vector<char> ans(a.size()+b.size()+1);
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++){
            ans[i+j] += a[i] * b[j];
            ans[i+j+1] += ans[i+j]/10;
            ans[i+j] %= 10;
        }
    }
    while(ans.size()>1 && ans.back()==0) ans.pop_back();
    return ans;
}
vector<char> quickPow(int n,int m){
    vector<char> ans = {1},pow = {static_cast<char>(n)};
    while(m){
        if(m&1){
            ans = mul(ans,pow);
        }
        pow = mul(pow,pow);
        m >>= 1;
        cout<<m<<endl;
    }
    return ans;
}
int main() {
    freopen("Testlib.in", "r", stdin);
    freopen("prime.out", "w", stdout);
    vector<char> a = quickPow(2,136279841);
    // vector<char> a = quickPow(10, 9);
    for(char & i : a) {
        if (i == 0) i=9;
        else {
            i--;
            break;
        }
    }
    while(a.size()>1 && a.back()==0) a.pop_back();
    for(int i = a.size()-1;~i; i--){
        printf("%c",a[i]+'0');
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}