//P9230 [蓝桥杯 2023 省 A] 填空问题
//记得把文件读写流和define注释掉
//4430091
//4165637
/*
#include <bits/stdc++.h>
using namespace std;
bool cheak(string &s) {
    int n = s.length();
    int l = 0,r = 0;
    for (int i = 0; i < n/2; i++) {
        l+=s[i]-'0';
    }
    for (int i = n/2; i < n; i++) {
        r+=s[i]-'0';
    }
    return l == r;
}
int AFunc() {
    int ans = 0;
    for(int i = 1; i<=100000000;i++){
        string st = to_string(i);
        if(st.length() % 2 == 0) {
            if(cheak(st)) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
int ans = 0;
void BFunc(int n,int cont) {
    if(n == 30) {
        if(cont == 70)ans++;
        return;
    }
    if(cont == 100) {
        return;
    }
    BFunc(n+1,cont+10);
    BFunc(n+1,0);
    return;
}
int main() {
    BFunc(0,0);
    cout << ans << endl;
}
*/
#include<bits/stdc++.h>
using namespace std;

char pid;
int main() {
    cin >> pid;
    if(pid == 'A')
        puts("4430091");
    else
        puts("4165637");
    return 0;
}