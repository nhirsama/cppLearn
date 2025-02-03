//D. Harder Problem
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;

void Func() {
    int n;
    cin >> n;
    int cnt = n;
    int arr[n + 5], barr[n + 5];
    vector<bool> st(n + 5, false);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        if (!st[arr[i]]) barr[i] = arr[i], st[arr[i]] = true;
        else {
            while (st[cnt]) cnt--;
            barr[i] = cnt;
            st[cnt] = true;
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", barr[i]);
    }
    printf("\n");
}

int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--) {
        Func();
    }
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
