#define LOCAL
//P8306 【模板】字典树
//835. Trie字符串统计
//记得把文件重定向注释掉
/*
#include <bits/stdc++.h>
using namespace std;
int TrieTree[1000100][26];
int cnt[1000100];
int idx = 1;
void insert(string &s){
    int p = 0;
    for (int i = 0; s[i];i++){
        int u = s[i] - 'a';
        if (!TrieTree[p][u]){
            TrieTree[p][u] = ++idx;
        }
        p = TrieTree[p][u];
    }
    cnt[p]++;
}
int query(string &s){
    int p = 0;
    for (int i = 0; s[i];i++){
        int u = s[i] - 'a';
        if (!TrieTree[p][u]) return 0;
        p = TrieTree[p][u];
    }
    return cnt[p];
}
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    int N;
    cin >> N;
    while (N--) {
        char a;
        cin>>a;
        string s;
        cin >> s;
        if (a == 'I'){
            insert(s);
        }
        else {
            cout<<query(s)<<endl;
        }
    }
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
int Tree[3000010][64];
int cnt[3000010];
int idx = 0;
int toInt(char &a) {
    if (a >= '0' && a <= '9') {
        return a-'0'+1;
    }
    if (a >= 'a' && a <= 'z') {
        return a-'a'+11;
    }
    if (a >= 'A' && a <= 'Z') {
        return a-'A'+38;
    }
}
void insert(string &s) {
    int p = 0;
    for (char c : s) {
        int u = toInt(c);
        if (!Tree[p][u]) {
            Tree[p][u] = ++idx;
        }
        p = Tree[p][u];
        cnt[p]++;
    }
}
int query(string &s) {
    int p = 0;
    for (char c : s) {
        int u = toInt(c);
        if (!Tree[p][u]) {
            return 0;
        }
        p = Tree[p][u];
    }
    return cnt[p];
}
int main() {
#ifdef LOCAL
    freopen("inAndoutFile/P8306_1.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n,q;
        memset(cnt, 0, sizeof(cnt[0])*idx);
        memset(Tree, 0, sizeof(Tree[0])*idx);
        idx = 0;
        cin >> n >> q;
        while (n--) {
            string s;
            cin >> s;
            insert(s);
        }
        while (q--) {
            string s;
            cin >> s;
            cout << query(s) << endl;
        }
    }
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}