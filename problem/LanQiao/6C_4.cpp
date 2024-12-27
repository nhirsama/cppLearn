#include <bits/stdc++.h>
using namespace std;
int a = 0;
bool v[10];
void dfs(string s,int n){
    if(n == 9){
        double aa = s[0],ab = s[1],ac = s[2],ad = s[3] * 100 + s[4] * 10 + s[5],ae = s[6]*100+s[7]*10+s[8];
        if(aa+ab/ac+ad/ae == 10) a++;
        return;
    }
    for(int i = 1; i <= 9; i++){
        if(v[i]) continue;
        v[i] = true;
        string s1 = s;
        s1.push_back(i);
        dfs(s1,n+1);
        v[i] = false;
    }
}
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    dfs("",0);
    cout << a << endl;

#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}