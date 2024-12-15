#include <iostream>
using namespace std;
const int mod = 1e9 + 7;
int ans = 0;
bool st[1000];

void dfs(int a, int b, int c) {
    if (a == b) {
        ans++;
        return;
    }
    for (int i = 1; i <= b; i++) {
        if (!st[i] && c * i % 2 == 0) {
            //if (!st[i]) {
            st[i] = true;
            dfs(a + 1, b, i);
            st[i] = false;
        }
    }
}

int main() {
    int n;
    cin >> n;
    dfs(0, n, 0);
    cout << ans;
}

// 64 位输出请用 printf("%lld")
