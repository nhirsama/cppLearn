//C. Game of Mathletes
#include <bits/stdc++.h>
using namespace std;

void del(int a[], int &n, int &endptr) {
    swap(a[n], a[endptr]);
    endptr--;
}

void Func() {
    int n, k;
    cin >> n >> k;
    int arr[n + 10];
    int ans = 0;
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    sort(arr, arr + n);
    int r = n - 1, l = 0;
    while (r > l) {
        if (arr[r] + arr[l] == k) {
            ans++;
            r--;
            l++;
        }
        if (arr[r] + arr[l] > k) {
            r--;
        }
        if (arr[r] + arr[l] < k) {
            l++;
        }
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Func();
    }
    return 0;
}
