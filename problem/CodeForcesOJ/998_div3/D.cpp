//D. Subtract Min Sort
#include <bits/stdc++.h>
using namespace std;
void Func() {
    int n;
    cin >> n;
    int arr[n+10];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    bool flag = true;
    for (int i = 0; i < n-1; i++) {
        if (arr[i] <= arr[i+1]) {
            arr[i+1]-=arr[i];
            arr[i]=0;
        }
        else if(arr[i] > arr[i+1]) {
            flag = false;
        }
    }
    if (flag) {
        puts("YES");
    }
    else {
        puts("NO");
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Func();
    }
    return 0;
}
