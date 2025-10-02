#include <stdio.h>
int arr[200000];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
            ans += arr[i] * 2;
        }
        for (int i = 0; i < 2; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] > arr[j]) {
                    int t = arr[j];
                    arr[j] = arr[i];
                    arr[i] = t;
                }
            }
        }
        ans -= arr[0] + arr[1];
        printf("%lld\n", ans);
    }
    return 0;
}
