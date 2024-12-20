#define LOCAL
//P1381 单词背诵
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> ma;
vector<string> v;
int visited[1005];
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        ma[s] = i;
    }
    int m;
    cin >> m;
    int ans1 = 0;
    for (int i = 1; i <= m; i++) {
        string s;
        cin >> s;
        v.push_back(s);
        if (ma.count(s)) {
            if(!visited[ma[s]]) {
                ans1++;
                visited[ma[s]] = 1;
            }
        }
    }
    int i = 1, j = 1;
    int cnt = 0;
    int ans2 = 0x3f3f3f3f;
    memset(visited, 0, sizeof(visited));
    while (j<=m) {
        if (ma.count(v[j])) {
            if (visited[ma[v[j]]] == 0)cnt++;
            visited[ma[v[j]]]++;
        }
        while (((!ma.count(v[i])) || visited[ma[v[i]]] > 1) && i<=j) {
            if (ma.count(v[i])) {
                visited[ma[v[i]]]--;
            }
            i++;
        }
        if (cnt == ans1) {
            ans2 = min(ans2, j-i+1);
        }
        j++;
    }
    cout << ans1 << "\n" << ans2 << endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}