//B. 安保系统
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long int ll;
#define x first
#define y second
#define endl '\n'
#define space << ' '
typedef pair<int, int> pii;
int n, l;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> l >> n) {
        bool pass = false;
        vector<char> v(n + 1);
        vector<bool> st(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> v[i];
        vector<char> ans;
        sort(v.begin() + 1, v.end());
        auto dfs = [&](auto self, int a, bool flag, int cnt, int fn) {
            if (l == a && flag && fn >= 2) {
                pass = true;
                for (auto b: ans) {
                    cout << b;
                }
                cout << endl;
                return;
            }
            if (l == a) {
                return;
            }
            for (int i = cnt + 1; i <= n; i++) {
                if (st[i]) continue;
                st[i] = true;
                ans.push_back(v[i]);
                bool aaa = flag;
                int fnnn = fn;
                if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u') {
                    aaa = true;
                } else fnnn++;
                self(self, a + 1, aaa, i, fnnn);
                st[i] = false;
                ans.pop_back();
            }
        };
        dfs(dfs, 0, false, 0, 0);
        if (!pass) cout << "No Password!" << endl;
    }
    return 0;
}
