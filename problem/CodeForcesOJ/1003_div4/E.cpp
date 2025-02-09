#include <bits/stdc++.h>
using namespace std;
void Func(){
    int n,m,k;
    cin>>n>>m>>k;
    if (abs(n-m)>k || max(n,m)<k) {
        puts("-1");
        return;
    }
    if (n>m) {
        for (int i=1; i<=k; i++) {
            cout<<0;
        }
        n-=k;
        while (n||m) {
            if (m) {cout << 1;m--;}
            if (n) {cout<< 0 ;n--;}
        }
    }
    else {
        for (int i=1; i<=k; i++) {
            cout<<1;
        }
        m-=k;
        while (n||m) {
            if (n) {cout<< 0 ;n--;}
            if (m) {cout << 1;m--;}

        }
    }
    cout<<endl;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        Func();
    }
    return 0;
}
