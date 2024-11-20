//A - DIY
#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
void Func() {
    int v;
    int arr2[N];
    cin>>v;
    for(int i =1 ; i <=v;i++) {
        cin>>arr2[i];
    }
    sort(arr2+1,arr2+v+1);
    int m = 0x7FFFFFFF;
    int n = 0;
    for(int i =1;i<=v;i++) {
        if(arr2[i] == m) {
            arr2[n++] = arr2[i];
            m = 0x7FFFFFFF;
            continue;
        }
        m = arr2[i];
    }
    if(n < 4) {
        cout<<"NO\n";
        return;
    }
    for(int i = 0 ; i < n/2;i++) {
        for(int k = 0 ; k < 2;k++) {
            int j = n-1-i+k;
            cout<<"YES\n";
            cout<< arr2[i] << ' '<< arr2[i+1] << ' '
                << arr2[i] << ' ' << arr2[j] << ' '
                << arr2[j-1] << ' ' << arr2[i+1] << ' '
                << arr2[j-1] << ' ' << arr2[j] << '\n';
            return;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i =0 ; i < n ; i++) {
        Func();
    }
    return 0;
}