//P1045 [NOIP2003 普及组] 麦森数
//记得把文件重定向注释掉
#define LOCAL
#include <bits/stdc++.h>
using namespace std;
vector<char> mul(vector<char> &a, vector<char> &b) {
    if(a.size() > b.size())return mul(a, b);
    vector<char> ans(a.size() + b.size()+1,0);
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < b.size(); j++) {
            ans[i+j] += (a[i] * b[j]);
            if(ans[i+j] >=10) {
                ans[i+j+1] += ans[i+j] / 10;
                ans[i+j] %= 10;
            }
        }
    }
    while(ans.size()>500) ans.pop_back();
    while(ans.size()<500) ans.push_back(0);
    return ans;
}
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    int p;
    cin >> p;
    printf("%d\n",(int)(log10(2)*p+1));
    vector<char> ans;
    ans.push_back(1);
    vector<char> pow;
    pow.push_back(2);
    while(p>0){
        if(p&1){
            ans = mul(ans,pow);
        }
        pow =mul(pow,pow);
        p>>=1;
    }
    int aaa = 0;
    if(ans[aaa] != 0)ans[aaa]-=1;
    else {
        while(ans[aaa] == 0) {
            ans[aaa++] = 9;
        }
        ans[aaa]-=1;
    }
    int num = 0;
    for (int i = ans.size() - 1; i >= 0; i--) {
        printf("%d",ans[i]);
        if(++num == 50) {
            printf("\n");
            num = 0;
        }
    }
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}