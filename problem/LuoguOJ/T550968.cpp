
//模板
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    int n;
    long long ans = 0;
    int arr[100010][2];
    cin >> n;
    long long error = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1];
        if(!arr[i][1])error++;
        else ans+=arr[i][0];
    }
    cout << error*20+ans << endl;

#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}