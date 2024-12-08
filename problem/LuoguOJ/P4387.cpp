//P4387 【深基15.习9】验证栈序列
//记得把文件读写流和define注释掉
#include <bits/stdc++.h>
using namespace std;
string Func() {
    stack <int>s;
    int n;
    cin>>n;
    int arr[n+5];
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    int pushed[n+5];
    for (int i = 0; i < n; i++) {
        cin>>pushed[i];
    }
    int j = 0;
    for (int i = 0; i < n; i++) {
        s.push(arr[i]);
        while (!s.empty() && s.top() == pushed[j]) {
            s.pop();
            j++;
        }
    }
    if(s.empty()) {
        return "Yes";
    }
    else {
        return "No";
    }
}
int main() {
    int q;
    cin >> q;
    while (q--) {
        cout << Func() << endl;
    }
    return 0;
}