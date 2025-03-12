#include <bits/stdc++.h>
using namespace std;
int max1 = 0;
int s[10000];
int powSum(int a){
    int ans = 0;
    while (a) {
        ans += (a%10)*(a%10);
        a /= 10;
    }
    return ans;
}
int aa(int a) {
    while (s[a] <= 10000) {
        a = powSum(a);
        s[a]++;
    }
    return a;
}
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    // for (int i = 1; i <= 10000; i++) {
    //     //s = set<int>();
    //     powSum(i);
    // }
    // for (int i = 1; i <= 1000; i++) {
    //     1009_div3(i);
    // }
    // cout<<max1<<endl;
    cout << 145 << endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}