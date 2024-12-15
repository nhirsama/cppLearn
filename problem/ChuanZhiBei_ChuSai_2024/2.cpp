#include <bits/stdc++.h>
using namespace std;
string str;
int aa(char a, char b) {
    if (a == b)return 0;
    if (a > b)return min(a - b, b+26-a);
    if (a < b)return aa(b,a);
    return -1;
}
int toStr(char a) {
    int ans = 0;
    for (char b : str) {
        ans += aa(a, b);
    }
    return ans;
}
int main() {
    cin >> str;
    int ans = 2147483647;
    for (char a = 'a'; a <= 'z'; a++) {
        int b = toStr(a);
        if (ans > b) ans = b;
    }
    cout << ans << endl;
}