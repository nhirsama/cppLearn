#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l;
    cin >> l >> n;
    n--;
    string s;
    stack<char> st;
    for (int i = 1; i <= l; i++) {
        st.push('z' - n % 26);
        n /= 26;
    }
    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
    return 0;
}
