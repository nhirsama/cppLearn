//P1045 [NOIP2003 普及组] 麦森数
//记得把文件重定向注释掉
#define LOCAL
#include <bits/stdc++.h>
using namespace std;
vector<char> mul(vector<char> &a, vector<char> &b) {
    vector<char> ans;

    return ans;
}
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    int p;
    cin >> p;
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
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i];
    }
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}