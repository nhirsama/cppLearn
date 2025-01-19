//B. Farmer John's Card Game
#include <bits/stdc++.h>
using namespace std;

void Func() {
    int n, m;
    cin >> n >> m;
    int arr[2005]{0};
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            int a;
            cin >> a;
            arr[a] = i;
        }
    }
    int ans[2005]{0};
    int cnt = 1;
    bool flag = true;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0) ans[cnt++] = arr[i * n + j];
            else if (arr[i * n + j] != arr[j])flag = false;
        }
    }
    if (flag == true) {
        for (int i = 1; i <= n; i++) {
            printf("%d ", ans[i]);
        }
        printf("\n");
    } else puts("-1");
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Func();
    }
    return 0;
}
